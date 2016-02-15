#include "y.tab.h"

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

