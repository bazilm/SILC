#include "y.tab.h"


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
