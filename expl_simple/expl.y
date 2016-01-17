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
char * sval;
struct NodeTag* nval;
}

%token BEG DECL ENDDECL INTEGER END READ WRITE EQ NE LE GE AND OR NOT IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token <ival> CONST
%token <nval> STRCONST
%token <nval> VAR
%type <nval> expr stmt stmt_list var_list

%left AND OR
%nonassoc '=' EQ '>' '<' LE GE NE NOT
%left '%'
%left '+' '-'
%left '*' '/'


%%

program: BEG declblock stmt_list END				{interpret($3);	return 0;			}
	 |error 						{ return 0;					}
	 ;

declblock:DECL decl_stmt ENDDECL	
	 |
	 ;

decl_stmt:	decl_stmt INTEGER var_list ';'			{makeSTable($3,INT);}
		|INTEGER var_list ';'				{makeSTable($2,INT);}
		;

var_list: var_list ',' VAR 					{$3->var.index=NULL;$$=makeOperNode('S',2,$1,$3);	}
	|var_list ',' VAR'['CONST']'  				{$3->var.index=makeConNode($5,NULL);$$=makeOperNode('S',2,$1,$3); 	}
	|VAR							{$1->var.index=NULL;$$=$1;			}
	|VAR'['CONST']'						{$1->var.index=makeConNode($3,NULL);$$=$1;			}
	;


stmt_list: stmt_list stmt					{$$ = makeOperNode('$',2,$1,$2);	}
	   |stmt						{$$ = $1;				}
    	  

stmt: 	READ '(' VAR ')' ';'	        			{$$ = makeOperNode(READ,1,$3);			}
	|READ '(' VAR '['expr']'')' ';'				{$3->var.index=$5;$$=makeOperNode(READ,1,$3);	}
 	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);			}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);		}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);			}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);		}
	|VAR '=' expr ';'					{$$ = makeOperNode('=',2,$1,$3);		}
	|VAR'['expr']' '=' expr ';'				{$1->var.index=$3;$$ = makeOperNode('=',2,$1,$6);}
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
	|expr EQ expr				{$$ = makeOperNode(EQ,2,$1,$3);		}
	|expr '<' expr				{$$ = makeOperNode('<',2,$1,$3);	}
	|expr '>' expr				{$$ = makeOperNode('>',2,$1,$3);	}
	|expr LE expr				{$$ = makeOperNode(LE,2,$1,$3);		}
	|expr GE expr				{$$ = makeOperNode(GE,2,$1,$3);		}
	|expr NE expr				{$$ = makeOperNode(NE,2,$1,$3);		}
	|'('expr EQ expr ')'			{$$ = makeOperNode(EQ,2,$2,$4);		}
	|'('expr '<' expr')'			{$$ = makeOperNode('<',2,$2,$4);	}
	|'('expr '>' expr')'			{$$ = makeOperNode('>',2,$2,$4);	}
	|'('expr LE expr ')'			{$$ = makeOperNode(LE,2,$2,$4);		}
	|'('expr GE expr ')'			{$$ = makeOperNode(GE,2,$2,$4);		}
	|'('expr NE expr ')'			{$$ = makeOperNode(NE,2,$2,$4);		}
	|expr AND expr				{$$ = makeOperNode(AND,2,$1,$3);	}
	|expr OR expr				{$$ = makeOperNode(OR,2,$1,$3);		}
	|NOT expr				{$$ = makeOperNode(NOT,1,$2);		}
	|CONST					{$$ = makeConNode($1,NULL);		}
	|STRCONST				{$$ = $1;		}
	|VAR					{$1->var.index=NULL;$$ = $1;		}
	|VAR'['expr']'				{$1->var.index=$3;$$=$1;		}
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

void makeSTable(Node * root,Type type)
{
STable * sTableEntry;
switch(root->nodeType)
{
	
	case OPERATOR:
			{
			makeSTable(&root->oper.operands[0],type);
			makeSTable(&root->oper.operands[1],type);
			break;
			}

	case VARIABLE:
			{
			sTableEntry = LookUp(root->var.name);
			if(!sTableEntry)
				{
				if(root->var.index==NULL)
					GInstall(root->var.name,type,1);
			
				else if(interpret(&root->var.index)<1)
					{
					printf("Error: Cant have size less than 1\n");
					exit(1);
					}
				else
					GInstall(root->var.name,type,interpret(&root->var.index));
				break;
				}
			else
				{
				printf("Error:Variable %s declared once\n",root->var.name);
				exit(1);
				}
			}
}
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
		sTable->binding = malloc(sizeof(int)*size);
		break;
		}

	case BOOLEAN:
		{
		sTable->size=1;
		sTable->binding = malloc(sizeof(bool)*size);
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

	
Node * makeConNode(int value,char * string)
{

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
if(!string)
	{
	p->nodeType = CONSTANT;
	p->type = INT;
	p->con.value = value;
	}
else
	{
	p->nodeType = CONSTANT;
	p->type = STRING;
	p->con.string = malloc(sizeof(string));
	strncpy(p->con.string,string+1,strlen(string)-2);
	}
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
p->var.index=0;
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
	//printf("Error: Parse Tree root NULL\n");
	return 0;
	}


switch(root->nodeType)
{
case CONSTANT:
	{
	if(root->type==INT)
		return root->con.value;
	else
		return root->con.string;
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
	
	return *((int *)sTableEntry->binding + interpret(root->var.index));
	
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
				printf("Type Mismatch in %c \n",root->oper.op);
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
				printf("Type Mismatch in %c\n",root->oper.op);
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
				printf("Type Mismatch in %c\n",root->oper.op);
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
				printf("Type Mismatch in %c\n",root->oper.op);
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
				printf("Type Mismatch in %c\n",root->oper.op);
				exit(1);
				}
			break;
			}

		case '=':
			{
			
			oper1 = interpret(&root->oper.operands[1]);
			sTableEntry = LookUp(root->oper.operands[0].var.name);

			
			if(!sTableEntry)
				{printf("Error: Variable %s not declared\n",root->oper.operands[0].var.name);
				exit(1);
				}
			if(sTableEntry->type != root->oper.operands[1].type)
				{
				printf("Type mismatch in =\n");
				exit(1);
				}	

			*((int *)(sTableEntry->binding)+interpret(root->oper.operands[0].var.index)) = oper1;
			
			
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
			if((root->oper.operands[0].type==BOOLEAN)&&(root->oper.operands[1].type==BOOLEAN))
			{
				root->type = BOOLEAN;
				return interpret(&root->oper.operands[0])&&interpret(&root->oper.operands[1]);
			}
			else
			{
				
				printf("Type Mismatch in AND\n");
				exit(1);
				
			}
			break;}

		case OR:
			{
			oper1 = interpret(&root->oper.operands[0]);
			oper2 = interpret(&root->oper.operands[1]);
			if((root->oper.operands[0].type ==BOOLEAN)&& (root->oper.operands[1].type==BOOLEAN))
			{
				root->type = BOOLEAN;
				return interpret(&root->oper.operands[0])||interpret(&root->oper.operands[1]);

			}
			else
			{
				
				printf("Type Mismatch in OR\n");
				exit(1);
				
			}
			break;}

		case NOT:
			{
			oper1 = interpret(&root->oper.operands[0]);
			
			if(root->oper.operands[0].type == BOOLEAN)
			{
				root->type = BOOLEAN;
				return !interpret(&root->oper.operands[0]);
			}
			else
			{
				
				printf("Type Mismatch in NOT\n");
				exit(1);
				
			}
			break;}
		case READ:
			{
			sTableEntry =  LookUp(root->oper.operands[0].var.name);
			
			if(!sTableEntry)
				{
				printf("here\n");
				printf("Error: Variable %s not declared\n",root->oper.operands[0].var.name);
				exit(1);
				}
			
			scanf("%d",(int *)(sTableEntry->binding)+interpret(root->oper.operands[0].var.index));
						
			return 1;
			break;
			}

		case WRITE:
			{
			
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
				printf("%d\n",*((int *)(sTableEntry->binding)+interpret(root->oper.operands[0].var.index)));
				
			}

			else
				{
				oper1 = interpret(&root->oper.operands[0]);
				if(root->oper.operands[0].type==INT)
					printf("%d\n",oper1);
				else
					printf("%s\n",(char*)oper1);
				}			
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








