%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "parse.h"

int *sym[26];
int lineNo;
%}

%union
{
int ival;
float fval;
char cval;
struct NodeTag* nval;
}

%token BEG END READ WRITE EQ NE LE GE AND OR NOT IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token <ival> INTEGER 
%token <cval> VAR
%type <nval> expr stmt stmt_list

%left AND OR
%nonassoc '=' EQ '>' '<' LE GE NE NOT
%left '%'
%left '+' '-'
%left '*' '/'


%%

program: BEG stmt_list END					{interpret($2);	return 0;			}
	 |error 						{ return 0;					}
	 ;

stmt_list: stmt_list stmt					{$$ = makeOperNode('$',2,$1,$2);	}
	   |stmt						{$$ = $1;				}
    	  

stmt: 	READ '(' VAR ')' ';'	        			{$$ = makeOperNode(READ,1,makeVarNode($3));	}
 	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);			}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);		}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);			}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);		}
	|VAR '=' expr ';'					{$$ = makeOperNode('=',2,makeVarNode($1),$3);	}
	;

expr : 
	 expr '+' expr 				{$$ = makeOperNode('+',2,$1,$3);	}
	|expr '-' expr				{$$ = makeOperNode('-',2,$1,$3);	}
	|expr '*' expr				{$$ = makeOperNode('*',2,$1,$3);	}
	|expr '/' expr				{$$ = makeOperNode('/',2,$1,$3);	}
	|expr '%' expr				{$$ = makeOperNode('%',2,$1,$3);	}
	|'('expr '+' expr')'			{$$ = makeOperNode('+',2,$2,$4);	}
	|'('expr '-' expr')'			{$$ = makeOperNode('-',2,$2,$4);	}
	|'('expr '*' expr')'			{$$ = makeOperNode('*',2,$2,$4);	}
	|'('expr '/' expr')'			{$$ = makeOperNode('/',2,$2,$4);	}
	|'('expr '%' expr')'			{$$ = makeOperNode('%',2,$2,$4);	}
	|expr EQ expr				{$$ = makeOperNode(EQUALS,2,$1,$3);	}
	|expr '<' expr				{$$ = makeOperNode('<',2,$1,$3);	}
	|expr '>' expr				{$$ = makeOperNode('>',2,$1,$3);	}
	|expr LE expr				{$$ = makeOperNode(LE,2,$1,$3);		}
	|expr GE expr				{$$ = makeOperNode(GE,2,$1,$3);		}
	|expr NE expr				{$$ = makeOperNode(NE,2,$1,$3);		}
	|'('expr EQ expr ')'			{$$ = makeOperNode(EQUALS,2,$2,$4);	}
	|'('expr '<' expr')'			{$$ = makeOperNode('<',2,$2,$4);	}
	|'('expr '>' expr')'			{$$ = makeOperNode('>',2,$2,$4);	}
	|'('expr LE expr ')'			{$$ = makeOperNode(LE,2,$2,$4);		}
	|'('expr GE expr ')'			{$$ = makeOperNode(GE,2,$2,$4);		}
	|'('expr NE expr ')'			{$$ = makeOperNode(NE,2,$2,$4);		}
	|expr AND expr				{$$ = makeOperNode(AND,2,$1,$3);	}
	|expr OR expr				{$$ = makeOperNode(OR,2,$1,$3);		}
	|NOT expr				{$$ = makeOperNode(NOT,1,$2);		}
	|INTEGER				{$$ = makeConNode($1);			}
	|VAR					{$$ = makeVarNode($1);			}
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


	
Node * makeConNode(int value)
{

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
p->nodeType = CONSTANT;
p->con.value = value;
return p;
}

Node * makeVarNode(char id)
{
Node *p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
p->nodeType = VARIABLE;
p->var.id = id - 'a';
return p;
}

Node * makeOperNode(int oper,int nops,...)
{

va_list temp_args;
va_start(temp_args,nops);

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}

p->nodeType = OPERATOR;
p->oper.op = oper;
p->oper.nops = nops;

if((p->oper.operands = malloc(nops * sizeof(Node)))==NULL)
	{
	printf("No memory\n");
	exit(0);
	}
	
int i=0;
for(i=0;i<nops;i++)
{
p->oper.operands[i] = *va_arg(temp_args,Node*);
}

return p;
}


int interpret(Node * root)
{

if(!root)
	{
	printf("Error: Parse Tree root NULL\n");
	return 0;
	}


switch(root->nodeType)
{
case CONSTANT:
	{
	return root->con.value;
	break;
	}

case VARIABLE:
	{
	if(sym[root->var.id]==NULL)
		{
		printf("Error: Variable %c not initialized\n",root->var.id+'a');
		return 0;
		}
	return *sym[root->var.id];
	break;
	}

case OPERATOR:
	{
	
	switch(root->oper.op)
	{
		case '+':
			{
			return interpret(&root->oper.operands[0]) + interpret(&root->oper.operands[1]);
			break;
			}

		case '-':
			{
			return interpret(&root->oper.operands[0]) - interpret(&root->oper.operands[1]);
			break;
			}
	
		case '*':
			{
			return interpret(&root->oper.operands[0]) * interpret(&root->oper.operands[1]);
			break;
			}
	
		case '/':
			{
			return interpret(&root->oper.operands[0]) / interpret(&root->oper.operands[1]);
			break;
			}
	
		case '%':
			{
			return interpret(&root->oper.operands[0]) % interpret(&root->oper.operands[1]);
			break;
			}

		case '=':
			{
			if (sym[root->oper.operands[0].var.id]==NULL)
				sym[root->oper.operands[0].var.id] = malloc(sizeof(int));

			*sym[root->oper.operands[0].var.id] = interpret(&root->oper.operands[1]);
			return 1;
			break;
			}	
			
		case EQ:
			{
			
			
			if (interpret(&root->oper.operands[0])==interpret(&root->oper.operands[1]))
				return 1;
				
			else
				return 0;
							
			}

		case '<':
			{
			
			if (interpret(&root->oper.operands[0])<interpret(&root->oper.operands[1]))
				return 1;
			else
				return 0;
			}

		case '>':
			{
			
			if (interpret(&root->oper.operands[0])>interpret(&root->oper.operands[1]))
				return 1;
			else
				return 0;
							
			}

		case LE:
			{
			
			if (interpret(&root->oper.operands[0])<=interpret(&root->oper.operands[1]))
				return 1;
			else
				return 0;
			}

		case GE:
			{
			
			if (interpret(&root->oper.operands[0])>=interpret(&root->oper.operands[1]))
				return 1;
			else
				return 0;
							
			}

		case NE:
			{
			if (interpret(&root->oper.operands[0])!=interpret(&root->oper.operands[1]))
				return 1;
			else
				return 0;
			}
	
		case AND:
			{
			return interpret(&root->oper.operands[0])&&interpret(&root->oper.operands[1]);
			}

		case OR:
			{
			return interpret(&root->oper.operands[0])||interpret(&root->oper.operands[1]);
			}

		case NOT:
			{
			return !interpret(&root->oper.operands[0]);
			}
		case READ:
			{
			
			if (sym[root->oper.operands[0].var.id]==NULL)
				sym[root->oper.operands[0].var.id] = malloc(sizeof(int));

			scanf("%d",sym[root->oper.operands[0].var.id]);
			
			
			return 1;
			break;
			}

		case WRITE:
			{
			if(root->oper.operands[0].nodeType == VARIABLE)
			{
			 if (sym[root->oper.operands[0].var.id]==NULL)
				printf("Error: Variable %c Not initialized\n",root->oper.operands[0].var.id+'a');

			 else
				printf("%d\n",*sym[root->oper.operands[0].var.id]);
			}

			else
				printf("%d\n",interpret(&root->oper.operands[0]));
			return 1;
			break;
			}

		case IF:
		       {
			if(interpret(&root->oper.operands[0]))
				interpret(&root->oper.operands[1]);
			else if(root->oper.nops==3)
				interpret(&root->oper.operands[2]);
			break;
			}

		case WHILE:
			{
			while(interpret(&root->oper.operands[0]))
				interpret(&root->oper.operands[1]);
			break;
			}

		case '$':
			{
			interpret(&root->oper.operands[0]);
			interpret(&root->oper.operands[1]);
			break;

			}
	}
	}
}
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
	sym[node->var.id] = 0;
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








