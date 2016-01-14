%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"

STable *sTableBeg,*sTableEnd;
int lineNo;
%}

%union
{
int ival;
struct NodeTag* nval;
}

%token BEG END READ WRITE EQ NE LE GE AND OR NOT IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token <ival> INTEGER 
%token <nval> VAR
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
    	  

stmt: 	READ '(' VAR ')' ';'	        			{$$ = makeOperNode(READ,1,$3);	}
 	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);			}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);		}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);			}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);		}
	|VAR '=' expr ';'					{$$ = makeOperNode('=',2,$1,$3);	}
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
	|expr EQ expr				{$$ = makeOperNode(EQ,2,$1,$3);	}
	|expr '<' expr				{$$ = makeOperNode('<',2,$1,$3);	}
	|expr '>' expr				{$$ = makeOperNode('>',2,$1,$3);	}
	|expr LE expr				{$$ = makeOperNode(LE,2,$1,$3);		}
	|expr GE expr				{$$ = makeOperNode(GE,2,$1,$3);		}
	|expr NE expr				{$$ = makeOperNode(NE,2,$1,$3);		}
	|'('expr EQ expr ')'			{$$ = makeOperNode(EQ,2,$2,$4);	}
	|'('expr '<' expr')'			{$$ = makeOperNode('<',2,$2,$4);	}
	|'('expr '>' expr')'			{$$ = makeOperNode('>',2,$2,$4);	}
	|'('expr LE expr ')'			{$$ = makeOperNode(LE,2,$2,$4);		}
	|'('expr GE expr ')'			{$$ = makeOperNode(GE,2,$2,$4);		}
	|'('expr NE expr ')'			{$$ = makeOperNode(NE,2,$2,$4);		}
	|expr AND expr				{$$ = makeOperNode(AND,2,$1,$3);	}
	|expr OR expr				{$$ = makeOperNode(OR,2,$1,$3);		}
	|NOT expr				{$$ = makeOperNode(NOT,1,$2);		}
	|INTEGER				{$$ = makeConNode($1);			}
	|VAR					{$$ = $1;			}
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


STable *GInstall(char *name,Type type,int size)
{
STable *sTable = malloc(sizeof(STable));
sTable->name = name;
sTable->type = type;

switch(type)
{
	case INT:
		{
		sTable->size = 1;
		sTable->binding = malloc(sizeof(int));
		break;
		}

	case BOOLEAN:
		{
		sTable->size=1;
		sTable->binding = malloc(sizeof(bool));
		break;
		}
}

sTable->next = NULL;

if(sTableBeg==NULL)
	{
	sTableBeg=sTable;
	sTableEnd=sTable;
	}
else
	{
	sTableEnd->next = sTable;
	sTableEnd = sTable;
	}
return sTableEnd;
}

STable *LookUp(char * name)
{
STable * sTable = sTableBeg;
while(sTable!=NULL)
	{
	if(strcmp(sTable->name,name)==0)
		return sTable;

	sTable=sTable->next;
	}
return NULL;
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
p->type = INT;
p->con.value = value;
return p;
}

Node * makeVarNode(char *name)
{

Node *p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
p->nodeType = VARIABLE;
p->type = INT;
p->var.name = malloc(sizeof(name));
strcpy(p->var.name,name);
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

STable * sTableEntry;

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
	sTableEntry = LookUp(root->var.name);
	if(sTableEntry==NULL)
		{
		printf("Error: Variable %s not declared\n",root->var.name);
		return 0;
		}

	else if(sTableEntry->size==0)
		{
		printf("Error: Variable %s not initialized\n",root->var.name);
		return 0;
		}
	root->type = sTableEntry->type;
	return *(int *)(sTableEntry->binding);
	break;
	}

case OPERATOR:
	{
	int oper1,oper2,oper3;
	switch(root->oper.op)
	{
		case '+':
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type == INT) && (root->oper.operands[1].type == INT))
				{
				root->type = INT;
				return oper1 + oper2;
				}
			else
				{
				printf("Type Mismatch in %c in line %d\n",root->oper.op,lineNo);
				exit(1);
				}
			break;
			}

		case '-':
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type == INT) && (root->oper.operands[1].type == INT))
				{
				root->type = INT;
				return oper1 - oper2;
				}
			else
				{
				printf("Type Mismatch in %c in line %d\n",root->oper.op,lineNo);
				exit(1);
				}
			break;
			}
	
		case '*':
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type == INT) && (root->oper.operands[1].type == INT))
				{
				root->type = INT;
				return oper1 * oper2;	
				}
			else
				{
				printf("Type Mismatch in %c in line %d\n",root->oper.op,lineNo);
				exit(1);
				}
			break;
			}
	
		case '/':
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type == INT) && (root->oper.operands[1].type == INT))
				{
				root->type = INT;
				return oper1 / oper2;
				}
			else
				{
				printf("Type Mismatch in %c in line %d\n",root->oper.op,lineNo);
				exit(1);
				}
			break;
			}
	
		case '%':
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type == INT) && (root->oper.operands[1].type == INT))
				{
				root->type = INT;
				return oper1 % oper2;
				}
			else
				{
				printf("Type Mismatch in %c in line %d\n",root->oper.op,lineNo);
				exit(1);
				}
			break;
			}

		case '=':
			{
			//printf("in =\n");
			oper1 = interpret(&root->oper.operands[1]);
			sTableEntry = LookUp(root->oper.operands[0].var.name);

			//printf("%s\n",root->oper.operands[0].var.name);
			if(!sTableEntry)
				sTableEntry = GInstall(root->oper.operands[0].var.name,root->oper.operands[1].type,1);

			*(int *)(sTableEntry->binding) = oper1;
			
			
			return 1;
			break;
			}	
			
		case EQ:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				if (oper1==oper2)
					return 1;
				
				else
					return 0;
			}
			else
			{
				
				printf("Type Mismatch in ==\n");
				exit(1);
				
			}
			break;
			}
		case '<':
			{
			
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				if (oper1<oper2)
					return 1;
				
				else
					return 0;
			}
			else
			{
				
				printf("Type Mismatch in <\n");
				exit(1);
				
			}
			break;
			}

		case '>':
			{
			
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				if (oper1>oper2)
					return 1;
				
				else
					return 0;
			}
			else
			{
				
				printf("Type Mismatch in >\n");
				exit(1);
				
			}
			break;
							
			}

		case LE:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				if (oper1<=oper2)
					return 1;
				
				else
					return 0;
			}
			else
			{
				
				printf("Type Mismatch in <=\n");
				exit(1);
				
			}
			break;
			}

		case GE:
			{
			
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				if (oper1>=oper2)
					return 1;
				
				else
					return 0;
			}
			else
			{
				
				printf("Type Mismatch in >=\n");
				exit(1);
				
			}
			break;		
			}

		case NE:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				if (oper1!=oper2)
					return 1;
				
				else
					return 0;
			}
			else
			{
				
				printf("Type Mismatch in !=\n");
				exit(1);
				
			}
			break;
			}
	
		case AND:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				return interpret(&root->oper.operands[0])&&interpret(&root->oper.operands[1]);
			}
			else
			{
				
				printf("Type Mismatch in ==\n");
				exit(1);
				
			}
			break;}

		case OR:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if(root->oper.operands[0].type == root->oper.operands[1].type)
			{
				root->type = BOOLEAN;
				return interpret(&root->oper.operands[0])||interpret(&root->oper.operands[1]);

			}
			else
			{
				
				printf("Type Mismatch in ==\n");
				exit(1);
				
			}
			break;}

		case NOT:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type == root->oper.operands[1].type))
			{
				root->type = BOOLEAN;
				return !interpret(&root->oper.operands[0]);
			}
			else
			{
				
				printf("Type Mismatch in ==\n");
				exit(1);
				
			}
			break;}
		case READ:
			{
			sTableEntry =  LookUp(root->oper.operands[0].var.name);
			
			if(!sTableEntry)
				sTableEntry = GInstall(root->oper.operands[0].var.name,INT,1);
			scanf("%d",(int *)(sTableEntry->binding));
						
			return 1;
			break;
			}

		case WRITE:
			{
			//printf("in write\n");
			if(root->oper.operands[0].nodeType == VARIABLE)
			{
			sTableEntry = LookUp(root->oper.operands[0].var.name);

			 if (!sTableEntry)
				{
				printf("Error: Variable %s Not declared\n",root->oper.operands[0].var.name);
				return 0;
				}
			 else if (sTableEntry->size==0)
				{
				printf("Error: Variable %s Not initialized\n",sTableEntry->name);
				return 0;
				}

			 else
				printf("%d\n",*(int *)(sTableEntry->binding));
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








