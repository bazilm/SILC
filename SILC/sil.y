%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"
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
struct typetable * typeTable;
struct IdList * idval;
}

%token TYPEDEF BEG DECL ENDDECL TYPE END READ WRITE TRUE FALSE EQ NE LE GE AND OR NOT IF THEN ELSE MAIN ENDIF WHILE DO ENDWHILE RET NEW FREE
%token <ival> CONST
%token <nval> STRCONST
%token <sval> VAR
%type <typeTable> TYPE
%type <nval> expr stmt stmt_list Main program Fdeflist Fdef Fbody Id
%type <argval> Farglist Fcalllist Fargtypelist
%type <idval> Fvarlist Gvarlist Fargvarlist
%left AND OR
%nonassoc '=' EQ '>' '<' LE GE NE NOT
%left '%'
%left '+' '-'
%left '*' '/'


%%

program: 	TypeDefBlock Gdeclblock Fdeflist Main 			{
								if($3)
									$$ = makeOperNode('S',2,$3,$4);
								else
									$$ = $4;
								
								root = $$;
								}
								
		|error						{return 0;}
		;

TypeDefBlock:	TypeDefBlock TYPEDEF VAR '{' Fdecllist '}'	{typeTableInstall($3);}
		|						{}
		;

Gdeclblock:	DECL Gdecllist ENDDECL				{}
		|						{}
		;

Gdecllist:	Gdecllist TYPE Gvarlist ';'			{makeSTable($3,$2);}
		|						{}
		;

Gvarlist:	Gvarlist ',' VAR				{$$=makeIdList($1,$3,NULL,1,NULL,0,0,0);	}
		|Gvarlist ',' '^' VAR				{$$=makeIdList($1,$4,NULL,1,NULL,0,1,0);	}
		|Gvarlist ',' VAR '[' CONST ']'			{$$=makeIdList($1,$3,NULL,$5,NULL,0,0,1);	}
		|Gvarlist ',' VAR '(' Farglist ')'		{$$=makeIdList($1,$3,NULL,1,$5,1,0,0);	}
		|VAR						{$$=makeIdList(NULL,$1,NULL,1,NULL,0,0,0);	}
		|'^' VAR					{$$=makeIdList(NULL,$2,NULL,1,NULL,0,1,0);	}
		|VAR '[' CONST ']'				{$$=makeIdList(NULL,$1,NULL,$3,NULL,0,0,1);	}
		|VAR '(' Farglist ')'				{$$=makeIdList(NULL,$1,NULL,1,$3,1,0,0);	}
		;


Farglist:	Farglist ';' Fargtypelist 			{$$ = joinArgList($1,$3);		}
		|Fargtypelist					{$$ = $1;				}
		;

Fargtypelist:	TYPE Fargvarlist 				{$$ = makeArgList(NULL,$2,$1);		}
		|						{$$ = NULL; 				}
		;

Fargvarlist:	Fargvarlist ',' VAR				{$$=makeIdList($1,$3,NULL,1,NULL,0,0,0);}
		|Fargvarlist ',' '&' VAR			{$$=makeIdList($1,$4,NULL,1,NULL,1,0,0);}
		|VAR						{$$=makeIdList(NULL,$1,NULL,1,NULL,0,0,0);}
		|'&' VAR					{$$=makeIdList(NULL,$2,NULL,1,NULL,1,0,0);}
		;

Fdeflist:	Fdeflist Fdef 					{if($$)
									$$ = makeOperNode('S',2,$1,$2);
								 else
									$$ = $2;
								}			
		|						{$$ = NULL;}
		
		;

Fdef:		TYPE VAR '(' Farglist ')' '{'Fdeclblock Fbody '}' {$$ = makeFuncNode($1,$2,$4,$8);}
		;

Fdeclblock:	DECL Fdecllist ENDDECL				{}
		|						{}
		;

Fdecllist:	Fdecllist TYPE Fvarlist ';'			{makeLTable($3,$2);}
		|						{}
		;

Fvarlist:	Fvarlist ',' VAR				{$$ =makeIdList($1,$3,NULL,1,NULL,0,0,0);}
		|Fvarlist ',' '^' VAR				{$$ =makeIdList($1,$4,NULL,1,NULL,0,1,1);}
		|VAR						{$$ =makeIdList(NULL,$1,NULL,1,NULL,0,0,0);}
		|'^' VAR					{$$ =makeIdList(NULL,$2,NULL,1,NULL,0,1,1);}
		;

Fbody:		BEG stmt_list END				{$$ = $2;}
		;

Main:		TYPE MAIN '('')''{'Fdeclblock Fbody '}'		{$$ = makeFuncNode($1,"main",NULL,$7);}
		;

stmt_list: stmt_list stmt					{$$ = makeOperNode('S',2,$1,$2);	}
	   |stmt						{$$ = $1;				}
    	  

stmt: 	READ '(' Id ')' ';'	        			{$$ = makeOperNode(READ,1,$3);			}
	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);			}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);		}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);			}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);		}
	|Id '=' expr ';'					{$$ = makeOperNode('=',2,$1,$3);		}
	|Id '=' NEW '('expr')' ';'				{$$ = makeOperNode(NEW,2,$1,$5);		}
	|FREE '(' Id ')' ';'					{$$ = makeOperNode(FREE,1,$3);			}
	|RET expr ';'						{$$ = makeOperNode('R',1,$2);			}
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
	|CONST					{$$ = makeConNode(INT,$1);		}
	|TRUE					{$$ = makeConNode(BOOLEAN,1);		}
	|FALSE					{$$ = makeConNode(BOOLEAN,0);		}
	|Id					{$$ = $1;				}
	|VAR'('Fcalllist')'			{$$ = makeOperNode('f',1,makeVarNode($1,NULL,$3,0));		}
	;

Id	:Id '.' VAR				{$$ = addInnerId($1,$3);					}
	|VAR					{$$ = makeVarNode($1,NULL,NULL,0);				}
	|VAR'['expr']'				{$$ = makeVarNode($1,$3,NULL,0);				}


Fcalllist:Fcalllist ',' expr			{$$ = makeCallList($1,$3);}
	  |expr					{$$ = makeCallList(NULL,$1);}					
	  |					{$$ = NULL;		}
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
initializeTypeTable();
initializeSymbolTable();
yyparse();

semanticAnalyzer(root);
if(!has_error)
{
out = fopen("sil.out","w");
fprintf(out,"START\n");
fprintf(out,"MOV SP,1535\n");
fprintf(out,"MOV BP,1535\n");
fprintf(out,"PUSH R0\n");
fprintf(out,"CALL main\n");
fprintf(out,"HALT\n");
compile(root);
}								
return 0;
}


void yyerror(char * s)
{
printf("Syntax Error in %d\n",lineNo);
}

