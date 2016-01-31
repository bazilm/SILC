%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"

STable *sTableBeg,*sTableEnd;
int lineNo;
bool has_error = false;
FILE * out;
int reg_count=-1;
int mem = 0;

#include "compiler.c"
%}

%union
{
int ival;
char * sval;
struct NodeTag* nval;
}

%token BEG DECL ENDDECL INTEGER BOOL END READ WRITE TRUE FALSE EQ NE LE GE AND OR NOT IF THEN ELSE ENDIF WHILE DO ENDWHILE
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

program: BEG declblock stmt_list END				{semanticAnalyzer($3);
								if(!has_error)
								{
								out = fopen("sil.out","w");
								fprintf(out,"START\n");
								fprintf(out,"MOV SP,1535\n");
								fprintf(out,"MOV BP,1535\n");
								compile($3);
								fprintf(out,"HALT");
								}
								return 0;}
	 |error 						{ return 0;					}
	 ;

declblock:DECL decl_stmt ENDDECL	
	 |
	 ;

decl_stmt:	decl_stmt INTEGER var_list ';'			{makeSTable($3,INT);}
		|decl_stmt BOOL var_list ';'			{makeSTable($3,BOOLEAN);}
		|INTEGER var_list ';'				{makeSTable($2,INT);}
		|BOOL var_list ';'				{makeSTable($2,BOOLEAN);}
		;

var_list: var_list ',' VAR 					{$$=makeOperNode('S',2,$1,makeVarNode($3,NULL,1));			}
	|var_list ',' VAR'['CONST']'  				{$$=makeOperNode('S',2,$1,makeVarNode($3,NULL,$5));}
	|VAR							{$$=makeVarNode($1,NULL,1);						}
	|VAR'['CONST']'						{$$=makeVarNode($1,NULL,$3);			}
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
				
				if(root->var.size<1)
					{
					printf("Error in %d: Cant have size less than 1\n",root->lineNo);
					has_error=true;
					}
				else
					GInstall(root->var.name,type,root->var.size);
				break;
				}
			else
				{
				printf("Error in %d :Variable %s declared once\n",root->lineNo,root->var.name);
				has_error=true;
				break;
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
		sTable->binding = mem++;
		break;
		}

	
	case BOOLEAN:
		{
		sTable->size=size;
		sTable->binding = mem++;
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

void setVariableValue(char *name,Node *index)
{
STable *sTableEntry = LookUp(name);
if(!index)
{
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
}
else
{
compile(index);
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
reg_count--;
}

}

void getVariableValue(char *name,Node *index)
{
STable *sTableEntry = LookUp(name);
if(!index)
{
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
}
else
{
compile(index);
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
reg_count--;
fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
}
}

	
Node * makeConNode(Type type,int value)
{

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
switch(type)
{
case INTEGER:
	{
	
	p->nodeType = CONSTANT;
	p->type = INT;
	p->con.value = value;
	break;
	}

case BOOLEAN:
	{
	p->nodeType = CONSTANT;
	p->type = BOOLEAN;
	p->con.value = value;
	break;
	}
}
p->lineNo=lineNo;
return p;
}

Node * makeVarNode(char *name,Node *index,int size)
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
p->var.size = size;
p->lineNo=lineNo;
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
p->lineNo=lineNo;
return p;
}

/*
int interpret(Node * root)
{

STable * sTableEntry;
int res1,res2,res3;
int nops;
Node *oper1,*oper2,*oper3;

if(!root)
	return 0;


switch(root->nodeType)
{
case CONSTANT:
	{
	return root->con.value;
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
	if(root->oper.nops>=2)
		oper2 = &root->oper.operands[1];

	if(root->oper.nops==3)
		oper3 = &root->oper.operands[2];
	nops = root->oper.nops;
	switch(root->oper.op)
	{
		case '+':
			{
			return interpret(oper1)+interpret(oper2);
			break;
			}

		case '-':
			{
			if(nops==1)
				return -interpret(oper1);
			else
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
			scanf("%d",&int_value);
			setVariableValue(oper1->var.name,oper1->var.index,makeConNode(INTEGER,int_value));
									
			return 1;
			break;
			}

		case WRITE:
			{
			
			if(oper1->nodeType == VARIABLE)
				printf("%d\n",getVariableValue(oper1->var.name,oper1->var.index));
					
			
			else
				printf("%d\n",interpret(oper1));
				
							
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
*/

void semanticAnalyzer(Node * root)
{
STable *sTableEntry;
Node * oper1,*oper2,*oper3;
int nops;
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
			printf("Error in %d: Variable %s not declared\n",root->lineNo,root->var.name);
			has_error = true;
			}
		else
			root->type = sTableEntry->type;

		if(root->var.index)
		{
		semanticAnalyzer(root->var.index);

		if(root->var.index->type!=INT)
			{
			printf("Error in %d: Index must be a number\n",root->lineNo);
			has_error=true;
			}
		}
		break;
		}

	case OPERATOR:
		{
		oper1 = &root->oper.operands[0];
		if(root->oper.nops>=2)
			oper2 = &root->oper.operands[1];

		if(root->oper.nops==3)
			oper3 = &root->oper.operands[2];
		nops = root->oper.nops;
		switch(root->oper.op)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
			if(nops==1)
			{
				semanticAnalyzer(oper1);
				root->type=oper1->type;
			}
			else
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			if((oper1->type == INT) && (oper2->type == INT))
				root->type = INT;
				
			else
				{
				printf("Error in %d: Type Error in %c \n",root->lineNo,root->oper.op);
				has_error = true;
				}
			}
			break;
			}

		case '=':
			{
			
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if(oper1->type != oper2->type)
				{
				printf("Error in %d: Type Error in =\n",root->lineNo);
				has_error = true;
				}

				
			break;
			}	
			
		case EQ:
		case '<':
		case '>':
		case LE:
		case GE:
		case NE:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if(oper1->type == INT && oper2->type==INT)
				root->type = BOOLEAN;
				
			else
			{
				printf("Error in %d: Type Error in logical operator\n",root->lineNo);
				has_error = true;
			}
			break;
			}
		case AND:
		case OR:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if((oper1->type == BOOLEAN) && (oper2->type==BOOLEAN))
				root->type = BOOLEAN;
				
			else
			{
				printf("Error in %d: Type Error in logical operator\n",root->lineNo);
				has_error = true;
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
				printf("Error in %d: Type Error in NOT\n",root->lineNo);
				has_error = true;
			}
			break;

			}
		case READ:
			{
			semanticAnalyzer(oper1);
			if(oper1->type==BOOLEAN)
				{
				printf("Error in %d: Type Error in READ\n",root->lineNo);
				has_error=true;
				}
			break;
			}

		case WRITE:
			{
			semanticAnalyzer(oper1);
			if(oper1->type==BOOLEAN)
				{
				printf("Error in %d: Type Error in READ\n",root->lineNo);
				has_error=true;
				}
			
			break;
			}

		case IF:
		       {
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			if(root->oper.nops==3)
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








