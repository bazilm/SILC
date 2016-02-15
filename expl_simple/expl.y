%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"

STable *sTableBeg,*sTableEnd;
LTable *lTableBeg,*lTableEnd;
int lineNo;
bool has_error = false;
FILE * out;
int reg_count=-1;
int mem = 0,if_count=1,while_count=1,fmem;

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
ArgList * argval;
IdList * idval;
}

%token BEG DECL ENDDECL INTEGER BOOL END READ WRITE TRUE FALSE EQ NE LE GE AND OR NOT IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token <ival> CONST
%token <nval> STRCONST
%token <sval> VAR
%type <nval> expr stmt stmt_list var_list
%type <argval> Farglist
%type <idval> Fvarlist Gvarlist
%left AND OR
%nonassoc '=' EQ '>' '<' LE GE NE NOT
%left '%'
%left '+' '-'
%left '*' '/'


%%

program: 	Gdeclblock Fdeflist Main 			{$$ = makeOperNode('S',2,$2,$3);
								semanticAnalyzer($$);
								if(!has_error)
								{
								out = fopen("sil.out","w");
								fprintf(out,"START\n");
								fprintf(out,"MOV SP,1535\n");
								fprintf(out,"MOV BP,1535\n");
								compile($$);
								fprintf(out,"HALT");
								}
								return 0;
								}
		|error						{return 0;}
		;

Gdeclblock:	DECL Gdecllist ENDDECL					{}
		;

Gdecllist:	Gdecllist INTEGER Gvarlist ';'				{makeSTable($3,INT);}
		|Gdecllist BOOL Gvarlist ';'				{makeSTable($3,BOOL);}
		|INTEGER Gvarlist ';'					{makeSTable($2,INT);}
		|BOOL Gvarlist ';'					{makeSTable($2,INT);}
		;

Gvarlist:	Gvarlist ',' VAR				{$$=makeIdList($1,$3,INT,1,NULL,0);}
		|Gvarlist ',' VAR '[' CONST ']'			{$$=makeIdList($1,$3,INT,$5,NULL,0);}
		|Gvarlist ',' VAR '(' Farglist ')'		{$$=makeIdList($1,$3,INT,1,$5,1);}
		|VAR						{$$=makeIdList(NULL,$1,INT,1,NULL,0);}
		|VAR '[' CONST ']'				{$$=makeIdList(NULL,$1,INT,$3,NULL,0);}
		|VAR '(' Farglist ')'				{$$=makeIdList(NULL,$1,INT,1,$3,1);}
		;

Farglist:	Farglist INTEGER Fvarlist ';'			{$$ = makeArgList($1,$3,INT);		}
		|Farglist BOOL Fvarlist ';'			{$$ = makeArgList($1,$3,BOOL);		}
		|INTEGER Fvarlist ';'				{$$ = makeArgList(NULL,$2,INT);	}
		|BOOL Fvarlist ';'				{$$ = makeArgList(NULL,$2,BOOL);	}
		;

Fvarlist:	Fvarlist ',' VAR				{$$=makeIdList($1,$3,INT,1,NULL,0);}
		|Fvarlist ',' '&' VAR				{$$=makeIdList($1,$4,INT,1,NULL,1);}
		|VAR						{$$=makeIdList(NULL,$2,INT,1,NULL,0);}
		|'&' VAR					{$$=makeIdList(NULL,$2,INT,1,NULL,1);}
		;

Fdeflist:	Fdeflist Fdef					{$$ = makeOperNode('S',2.$1,$2);}
		|Fdef						{$$ = $1;}
		;

Fdef:		INTEGER VAR '(' Farglist ')' '{'Fdecllist Fbody '}' {$$ = makeFuncNode(INT,$2,$4,$8);}
		|BOOL VAR '(' Farglist ')' '{' Fdecllist Fbody '}'  {$$ = makeFuncNode(BOOL,$2,$4,$8);}
		;

Fdecllist:	Fdecllist INTEGER Fvarlist ';'			{makeLTable($3,INT);}
		|Fdecllist BOOL Fvarlist ';'			{makeLTable($3,BOOL);}
		|INTEGER Fvarlist ';'				{makeLTable($3,INT);}
		|BOOL Fvarlist ';'				{makeLTable($3,BOOL):}
		;

Fvarlist:	Fvarlist ',' VAR				{$$ =makeIdList($1,$3,INT,1,NULL,0);}
		|VAR						{$$ =makeIdList(NULL,$1,INT,1,NULL,0);}
		;

Fbody:		BEG stmt_list ret_stmt	END			{$$ = makeOperNode('S',2,$1,$2);}
		;


stmt_list: stmt_list stmt					{$$ = makeOperNode('$',2,$1,$2);	}
	   |stmt						{$$ = $1;				}
    	  

stmt: 	READ '(' VAR ')' ';'	        			{$$ = makeOperNode(READ,1,makeVarNode($3,NULL,0));			}
	|READ '(' VAR '['expr']'')' ';'				{$$ = makeOperNode(READ,1,makeVarNode($3,$5,0));			}
 	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);						}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);					}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);						}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);					}
	|VAR '=' expr ';'					{$$ = makeOperNode('=',2,makeVarNode($1,NULL,0),$3);			}
	|VAR'['expr']' '=' expr ';'				{$$ = makeOperNode('=',2,makeVarNode($1,$3,0),$6);			}
	;

ret_stmt: RET expr ';'						{$$ = makeOperNode('R',1,$2);		}
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
	|VAR					{$$ = makeVarNode($1,NULL,0);		}
	|VAR'['expr']'				{$$ = makeVarNode($1,$3,0);		}
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




void freeNode (Node * node)
{
switch(node->nodeType)
{
case CONSTANT:
	{
	
	free(node);
	break;
	}

case VARIABLE:
	{
	
	free(node);
	break;
	}

case OPERATOR:
	{
	
	freeNode(&node->oper.operands[0]);
	freeNode(&node->oper.operands[1]);
	free(&node->oper.op);
	free(node);
	break;
	}
}
}








