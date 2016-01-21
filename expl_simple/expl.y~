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

%token BEG DECL ENDDECL INTEGER STR END READ WRITE EQ NE LE GE AND OR NOT IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token <ival> CONST
%token <nval> STRCONST
%token <sval> VAR
%type <nval> expr stmt stmt_list var_list

%left AND OR
%nonassoc '=' EQ '>' '<' LE GE NE NOT
%left '%'
%left '+' '-'
%left '*' '/'


%%

program: BEG declblock stmt_list END				{semanticAnalyzer($3);interpret($3);	return 0;			}
	 |error 						{ return 0;					}
	 ;

declblock:DECL decl_stmt ENDDECL	
	 |
	 ;

decl_stmt:	decl_stmt INTEGER var_list ';'			{makeSTable($3,INT);}
		|decl_stmt STR var_list ';'			{makeSTable($3,STRING);}
		|INTEGER var_list ';'				{makeSTable($2,INT);}
		|STR var_list ';'				{makeSTable($2,STRING);}
		;

var_list: var_list ',' VAR 					{$$=makeOperNode('S',2,$1,makeVarNode($3,NULL));	}
	|var_list ',' VAR'['CONST']'  				{$$=makeOperNode('S',2,makeVarNode($1,makeConNode($5,NULL)),$3); 	}
	|VAR							{$$=makeVarNode($1,NULL);			}
	|VAR'['CONST']'						{$$=makeVarNode($1,makeConNode($3,NULL));			}
	;


stmt_list: stmt_list stmt					{$$ = makeOperNode('$',2,$1,$2);	}
	   |stmt						{$$ = $1;				}
    	  

stmt: 	READ '(' VAR ')' ';'	        			{$$ = makeOperNode(READ,1,makeVarNode($3,NULL));			}
	|READ '(' VAR '['expr']'')' ';'				{$$ = makeOperNode(READ,1,makeVarNode($3,$5));	}
 	|WRITE '(' expr ')' ';'					{$$ = makeOperNode(WRITE,1,$3);			}
	|IF '('expr')' THEN stmt_list ELSE stmt_list ENDIF ';'	{$$ = makeOperNode(IF,3,$3,$6,$8);		}
	|IF '('expr')' THEN stmt_list ENDIF ';'			{$$ = makeOperNode(IF,2,$3,$6);			}
	|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'		{$$ = makeOperNode(WHILE,2,$3,$6);		}
	|VAR '=' expr ';'					{$$ = makeOperNode('=',2,makeVarNode($1,NULL),$3);		}
	|VAR'['expr']' '=' expr ';'				{$$ = makeOperNode('=',2,makeVarNode($1,$3),$6);}
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
	|CONST					{$$ = makeConNode($1,NULL);		}
	|STRCONST				{$$ = makeConNode(0,$1);		}
	|VAR					{$$ = makeVarNode($1,NULL);		}
	|VAR'['expr']'				{$$ = makeVarNode($1,$3);		}
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
			
				else if(interpret(root->var.index)<1)
					{
					printf("Error: Cant have size less than 1\n");
					exit(1);
					}
				else
					GInstall(root->var.name,type,interpret(root->var.index));
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
		sTable->size = size;
		sTable->binding = malloc(sizeof(int)*size);
		break;
		}

	case STRING:
		{
		sTable->size=24*size;
		sTable->binding = malloc(sizeof(char)*24*size);
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

void setVariableValue(char *name,Node *index,Node * value_node)
{
STable *sTableEntry = LookUp(name);

int offset = interpret(index);
int value = interpret(value_node);

if(sTableEntry->type==INT)
	*((int *)(sTableEntry->binding) + offset)=value;
else
	{
	int valAddress = sTableEntry->binding+offset*24;
	strcpy((char *)valAddress,(char *)value);
	
	}
}

int getVariableValue(char *name,Node *index)
{
STable *sTableEntry = LookUp(name);
int offset = interpret(index);

if(sTableEntry->type==INT)
	return *((int*)(sTableEntry->binding) + offset);
else
	{
	int valAddress = sTableEntry->binding+(offset*24);
	return valAddress;
	}
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
	strcpy(p->con.string,string);
	}
return p;
}

Node * makeVarNode(char *name,Node *index)
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
p->var.index=index;
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
int res1,res2,res3;
Node *oper1,*oper2,*oper3;

if(!root)
	return 0;


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
	return getVariableValue(root->var.name,root->var.index);
	break;
	}

case OPERATOR:
	{
	oper1 = &root->oper.operands[0];
	if(root->oper.nops==2)
		oper2 = &root->oper.operands[1];

	if(root->oper.nops==3)
		oper3 = &root->oper.operands[2];
	
	switch(root->oper.op)
	{
		case '+':
			{
			return interpret(oper1)+interpret(oper2);
			break;
			}

		case '-':
			{
			return interpret(oper1)-interpret(oper2);
			break;
			}
	
		case '*':
			{
			return interpret(oper1)*interpret(oper2);
			break;
			}
	
		case '/':
			{
			return interpret(oper1)/interpret(oper2);
			break;
			}
	
		case '%':
			{
			return interpret(oper1)%interpret(oper2);
			break;
			}

		case '=':
			{
			setVariableValue(oper1->var.name,oper1->var.index,oper2);
			return 1;
			break;
			}	
			
		case EQ:
			{
			return interpret(oper1)==interpret(oper2);
			break;
			}
		case '<':
			{
			return interpret(oper1)<interpret(oper2);
			break;
			}

		case '>':
			{
			
			return interpret(oper1)>interpret(oper2);
			break;
							
			}

		case LE:
			{
			return interpret(oper1)<=interpret(oper2);
			break;
			}

		case GE:
			{
			
			return interpret(oper1)>=interpret(oper2);
			break;		
			}

		case NE:
			{
			return interpret(oper1)!=interpret(oper2);
			break;
			}
	
		case AND:
			{
			return interpret(oper1)&&interpret(oper2);
			break;
			}

		case OR:
			{
			return interpret(oper1)||interpret(oper2);
			break;
			}

		case NOT:
			{
			return !interpret(oper1);
			break;
			}
		case READ:
			{
			int int_value;
			char *str_value = malloc(sizeof(char)*24);
			if(oper1->type==INT)
				{
				
				scanf("%d",&int_value);
				setVariableValue(oper1->var.name,oper1->var.index,makeConNode(int_value,NULL));
				}
			
			else
				{
				scanf("%s",str_value);
				setVariableValue(oper1->var.name,oper1->var.index,makeConNode(0,str_value));
				}
						
			return 1;
			break;
			}

		case WRITE:
			{
			
			if(oper1->nodeType == VARIABLE)
				{
			
				if(oper1->type==INT)
					printf("%d\n",getVariableValue(oper1->var.name,oper1->var.index));
				
				else
					{
					printf("%s\n",(char *)getVariableValue(oper1->var.name,oper1->var.index));
					}
				
				}

			else
				{
				
				if(oper1->type==INT)
					printf("%d\n",interpret(oper1));
				else if(oper1->type==STRING)
					printf("%s\n",(char*)interpret(oper1));
				}			
			return 1;
			break;
			}

		case IF:
		       {
			if(interpret(oper1))
				interpret(oper2);
			else if(root->oper.nops==3)
				interpret(oper3);
			break;
			}

		case WHILE:
			{
			while(interpret(oper1))
				interpret(oper2);
			break;
			}

		case '$':
			{
			interpret(oper1);
			interpret(oper2);
			break;

			}
	}
	}
}
}


void semanticAnalyzer(Node * root)
{
STable *sTableEntry;
Node * oper1,*oper2,*oper3;
if(!root)
	{
	printf("Parse Tree Root Null\n");
	exit(1);
	}
switch(root->nodeType)
{
	case CONSTANT:
		break;

	case VARIABLE:
		{
		sTableEntry = LookUp(root->var.name);
		
		if(sTableEntry==NULL)
			{
			printf("Error: Variable %s not declared\n",root->var.name);
			exit(1);
			}
		root->type = sTableEntry->type;
		break;
		}

	case OPERATOR:
		{
		oper1 = &root->oper.operands[0];
		if(root->oper.nops==2)
			oper2 = &root->oper.operands[1];

		if(root->oper.nops==3)
			oper3 = &root->oper.operands[2];

		switch(root->oper.op)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			if((oper1->type == INT) && (oper2->type == INT))
				root->type = INT;
				
			else
				{
				printf("Type Mismatch in %c \n",root->oper.op);
				exit(1);
				}
			break;
			}

		case '=':
			{
			
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if(oper1->type != oper2->type)
				{
				printf("Type mismatch in =\n");
				exit(1);
				}	
			break;
			}	
			
		case EQ:
		case '<':
		case '>':
		case LE:
		case GE:
		case NE:
		case AND:
		case OR:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if(oper1->type == oper2->type)
				root->type = BOOLEAN;
				
			else
			{
				printf("Type Mismatch in logical operator\n");
				exit(1);
			}
			break;
			}

		case NOT:
			{
			semanticAnalyzer(oper1);
			if(oper1->type == BOOLEAN)
				root->type = BOOLEAN;
			
			else
			{
				printf("Type Mismatch in NOT\n");
				exit(1);
			}
			break;

			}
		case READ:
			{
			semanticAnalyzer(oper1);
			break;
			}

		case WRITE:
			{
			semanticAnalyzer(oper1);
			break;
			}

		case IF:
		       {
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			semanticAnalyzer(oper3);
			break;
			}

		case WHILE:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			break;
			}

		case '$':
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
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








