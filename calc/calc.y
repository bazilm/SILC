%{
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include "calc.h"

int sym[26];

void findEnd();

%}

%union
{
int ival;
float fval;
struct NodeTag* nval;
}

%token <ival> INTEGER 
%type <nval> expr 


%left '+' '-'
%left '*' '/'

%%

program: program expr '\n'	{printf("= %d\n",interpret($2));//freeNode($2);
					}
	|error '\n'
	|
	;

expr :
	 expr '+' expr 		{$$ = makeOperNode('+',2,$1,$3);	}
	|expr '-' expr		{$$ = makeOperNode('-',2,$1,$3);	}
	|expr '*' expr		{$$ = makeOperNode('*',2,$1,$3);	}
	|expr '/' expr		{if (interpret($3)!=0)
					$$ = makeOperNode('/',2,$1,$3);	
				else
					{
					yyerror("Division By Zero Error\n");
					findEnd();
					}
				}
	|INTEGER		{$$ = makeConNode($1);	
				}
	;
%%

int main()
{
yyparse();
return 0;
}


void yyerror(char * s)
{
printf("%s\n",s);
}

void findEnd()
{
int i;
while ((i=yylex())!=';'||(i=yylex())!='\n');
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

Node * makeVarNode(int id)
{
Node *p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
p->nodeType = VARIABLE;
p->var.id = id;
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
switch(root->nodeType)
{
case CONSTANT:
	{
	
	return root->con.value;
	break;
	}

case VARIABLE:
	{
	return sym[root->var.id];
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








