%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"

STable *sTableBeg=NULL,*sTableEnd;
LTable *lTableBeg=NULL,*lTableEnd;
IdList * idListBeg=NULL, *idListEnd;
int lineNo;
bool has_error = false;
FILE * out;
int reg_count=-1;
int mem = 0,if_count=1,while_count=1,fmem=1;

#include "helper.c"
#include "semantics.c"
#include "compiler.c"
//#include "interpreter.c"

%}

%union
{
int ival;
char * sval;
struct NodeTag* nval;
struct ArgList * argval;
struct IdList * idval;
}

%token BEG DECL ENDDECL INTEGER BOOL END READ WRITE TRUE FALSE EQ NE LE GE AND OR NOT IF THEN ELSE MAIN ENDIF WHILE DO ENDWHILE RET
%token <ival> CONST
%token <nval> STRCONST
%token <sval> VAR
%type <nval> expr stmt stmt_list Main program Fdeflist Fdef Fbody 
%type <argval> Farglist Fcalllist
%type <idval> Fvarlist Gvarlist Fargvarlist
%left AND OR
%nonassoc '=' EQ '>' '<' LE GE NE NOT
%left '%'
%left '+' '-'
%left '*' '/'


%%

program: 	Gdeclblock Fdeflist Main 			{
								if($2)
									$$ = makeOperNode('S',2,$2,$3);
								else
									$$ = $3;
								semanticAnalyzer($$);
								if(!has_error)
								{
								out = fopen("sil.out","w");
								fprintf(out,"START\n");
								fprintf(out,"MOV SP,1535\n");
								fprintf(out,"MOV BP,1535\n");
								fprintf(out,"JMP MAIN\n");
								compile($$);
								fprintf(out,"MAIN:\n");
								fprintf(out,"PUSH R0\n");
								fprintf(out,"CALL main\n");
								fprintf(out,"HALT");
								}
								return 0;
								}
		|error						{return 0;}
		;

Gdeclblock:	DECL Gdecllist ENDDECL				{}
		|						{}
		;

Gdecllist:	Gdecllist INTEGER Gvarlist ';'			{makeSTable($3,INT);}
		|Gdecllist BOOL Gvarlist ';'			{makeSTable($3,BOOLEAN);}
		|						{}
		;

Gvarlist:	Gvarlist ',' VAR				{$$=makeIdList($1,$3,INT,1,NULL,0);}
		|Gvarlist ',' VAR '[' CONST ']'			{$$=makeIdList($1,$3,INT,$5,NULL,0);}
		|Gvarlist ',' VAR '(' Farglist ')'		{$$=makeIdList($1,$3,INT,1,$5,1);}
		|VAR						{$$=makeIdList(NULL,$1,INT,1,NULL,0);}
		|VAR '[' CONST ']'				{$$=makeIdList(NULL,$1,INT,$3,NULL,0);}
		|VAR '(' Farglist ')'				{$$=makeIdList(NULL,$1,INT,1,$3,1);}
		;

Farglist:	Farglist INTEGER Fargvarlist ';'		{$$ = makeArgList($1,$3,INT);		}
		|Farglist BOOL Fargvarlist ';'			{$$ = makeArgList($1,$3,BOOLEAN);		}
		|						{$$ = NULL;}
		;

Fargvarlist:	Fvarlist ',' VAR				{$$=makeIdList($1,$3,INT,1,NULL,0);}
		|Fvarlist ',' '&' VAR				{$$=makeIdList($1,$4,INT,1,NULL,1);}
		|VAR						{$$=makeIdList(NULL,$1,INT,1,NULL,0);}
		|'&' VAR					{$$=makeIdList(NULL,$2,INT,1,NULL,1);}
		;

Fdeflist:	Fdeflist Fdef 					{if($$)
									$$ = makeOperNode('S',2,$1,$2);
								 else
									$$ = $2;
								}			
		|						{$$ = NULL;}
		
		;

Fdef:		INTEGER VAR '(' Farglist ')' '{'Fdeclblock Fbody '}' {$$ = makeFuncNode(INT,$2,$4,$8);}
		|BOOL VAR '(' Farglist ')' '{' Fdeclblock Fbody '}'  {$$ = makeFuncNode(BOOLEAN,$2,$4,$8);}
		;

Fdeclblock:	DECL Fdecllist ENDDECL				{}
		|						{}
		;

Fdecllist:	Fdecllist INTEGER Fvarlist ';'			{makeLTable($3,INT);}
		|Fdecllist BOOL Fvarlist ';'			{makeLTable($3,BOOLEAN);}
		|						{}
		;

Fvarlist:	Fvarlist ',' VAR				{$$ =makeIdList($1,$3,INT,1,NULL,0);}
		|VAR						{$$ =makeIdList(NULL,$1,INT,1,NULL,0);}
		;

Fbody:		BEG stmt_list END				{$$ = $2;}
		;

Main:		INTEGER MAIN '('')''{'Fdeclblock Fbody '}'	{$$ = makeFuncNode(INT,"main",NULL,$7);}
		;

stmt_list: stmt_list stmt					{$$ = makeOperNode('S',2,$1,$2);	}
	   |stmt						{$$ = $1;				}
    	  

stmt: 	READ '(' VAR ')' ';'	        			{$$ = makeOperNode(READ,1,makeVarNode($3,NULL,NULL,0));			}
	|READ '(' VAR '['expr']'')' ';'				{$$ = makeOperNode(READ,1,makeVarNode($3,$5,NULL,0));			}
 	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);						}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);					}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);						}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);					}
	|VAR '=' expr ';'					{$$ = makeOperNode('=',2,makeVarNode($1,NULL,NULL,0),$3);		}
	|VAR'['expr']' '=' expr ';'				{$$ = makeOperNode('=',2,makeVarNode($1,$3,NULL,0),$6);			}
	|RET expr ';'						{$$ = makeOperNode('R',1,$2);						}
	;


expr : 
	 expr '+' expr 				{$$ = makeOperNode('+',2,$1,$3);	}
	|expr '-' expr				{$$ = makeOperNode('-',2,$1,$3);	}
	|expr '*' expr				{$$ = makeOperNode('*',2,$1,$3);	}
	|expr '/' expr				{$$ = makeOperNode('/',2,$1,$3);	}
	|expr '%' expr				{$$ = makeOperNode('%',2,$1,$3);	}
	|expr EQ expr				{$$ = makeOperNode(EQ,2,$1,$3);		}
	|expr '<' expr				{$$ = makeOperNode('<',2,$1,$3);	}
	|expr '>' expr				{$$ = makeOperNode('>',2,$1,$3);	}
	|expr LE expr				{$$ = makeOperNode(LE,2,$1,$3);		}
	|expr GE expr				{$$ = makeOperNode(GE,2,$1,$3);		}
	|expr NE expr				{$$ = makeOperNode(NE,2,$1,$3);		}
	|expr AND expr				{$$ = makeOperNode(AND,2,$1,$3);	}
	|expr OR expr				{$$ = makeOperNode(OR,2,$1,$3);		}
	|NOT expr				{$$ = makeOperNode(NOT,1,$2);		}
	|'-'expr				{$$ = makeOperNode('-',1,$2);		}
	|'('expr')'				{$$ = $2;				}
	|CONST					{$$ = makeConNode(INTEGER,$1);}
	|TRUE					{$$ = makeConNode(BOOLEAN,1);	}
	|FALSE					{$$ = makeConNode(BOOLEAN,0);}
	|VAR					{$$ = makeVarNode($1,NULL,NULL,0);		}
	|VAR'['expr']'				{$$ = makeVarNode($1,$3,NULL,0);		}
	|VAR'('Fcalllist')'			{$$ = makeOperNode('f',1,makeVarNode($1,NULL,$3,0));		}
	;

Fcalllist:Fcalllist ',' CONST			{$$ = makeCallList($1,NULL,INT,$3);}
	  |Fcalllist ',' VAR			{$$ = makeCallList($1,$3,INT,0);}
	  |Fcalllist ',' TRUE			{$$ = makeCallList($1,NULL,BOOLEAN,1);}
	  |Fcalllist ',' FALSE			{$$ = makeCallList($1,NULL,BOOLEAN,0);}
	  |CONST				{$$ = makeCallList(NULL,NULL,INT,$1);}
	  |VAR					{$$ = makeCallList(NULL,$1,INT,0);}
	  |TRUE					{$$ = makeCallList(NULL,NULL,BOOLEAN,1);}
	  |FALSE				{$$ = makeCallList(NULL,NULL,BOOLEAN,0);}
	  ;
%%

int main(int argc, char *argv[])
{
if(argc>1)
{
extern FILE * yyin;
yyin = fopen(argv[1],"r");
}

lineNo=1;
yyparse();
return 0;
}


void yyerror(char * s)
{
printf("%s:%d\n",s,lineNo);
}

