#include "y.tab.h"

LTable * lTable =NULL;
STable * sTable = NULL;
bool hasReturn = false;
void semanticAnalyzer(Node * root)
{

STable *sTableEntry;
LTable *lTableEntry;
Node * oper1,*oper2,*oper3;
int nops;



if(!root)
	{
	return;
	}
switch(root->nodeType)
{
	case CONSTANT:
		break;

	case VARIABLE:
		{
		
		
		lTableEntry = LLookUp(root->var.name,lTable);
		
		if(lTableEntry==NULL)
		{
		
			sTableEntry = LookUp(root->var.name);
			if(sTableEntry==NULL)
				{
				printf("Error in %d: Variable %s not declared\n",root->lineNo,root->var.name);
				has_error = true;
				}
			else
				{
				//printf("%s found from global Table in memory address %d\n",root->var.name,sTableEntry->binding);
				root->type = sTableEntry->type;
				}
		}
		else
			{
			//printf("%s found from local Table in memory address %d\n",root->var.name,lTableEntry->binding);
			root->type = lTableEntry->type;
			}
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

		case 'S':
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			break;
			}
		case 'F':
			{
			sTableEntry = LookUp(oper1->var.name);
			
			//no sTableEntry, so function not declared
			if(!sTableEntry)
			{
			printf("Error in %d: Function %s not declared\n",root->lineNo,oper1->var.name);
			has_error = true;
			}
			
			else 
				{
				//checking whether it is a function, func binding is set to -1
				if(sTableEntry->binding!=-1)
				{
				printf("Error in %d: %s is not a function\n",root->lineNo,oper1->var.name);
				has_error=true;
				break;
				}

				
				//checking whether return types match
				if(oper1->type!=sTableEntry->type)
				{
				printf("Error in %d: Return type mismatch in function %s\n",root->lineNo,oper1->var.name);
				has_error = true;
				}
				//setting sTable to be used by the function body
				sTable = sTableEntry;
				//setting lTable to be used by the function body
				lTable = sTable->symbolTable;
				
				//function has args, checking whether declaration and definition args match
				if(sTableEntry->args)
				{
				ArgList * funcArgList = oper1->var.argList;
				ArgList * symArgList = sTableEntry->args;
				
				while(symArgList!=NULL&&funcArgList!=NULL)
				{	
					//checking for name equivalence
					if(strcmp(symArgList->name,funcArgList->name)!=0)
					{
					printf("Error in %d: Arguments name mismatch in function %s\n",root->lineNo,oper1->var.name);
					has_error = true;
					}
					
					//checking for type equivalence
					if((symArgList->type!=funcArgList->type)||(symArgList->ref!=funcArgList->ref))
					{
					
					printf("Error in %d: Type mismatch in argument %s of function %s\n",root->lineNo,symArgList->name,oper1->var.name);
					has_error =true;
					}
						
				symArgList = symArgList->next;
				funcArgList = funcArgList->next;
				}
				//checking whether no. of arguments match
				if(symArgList!=NULL||funcArgList!=NULL)
				{
				printf("Error in %d: No of arguments doesnt match in function %s\n",root->lineNo,oper1->var.name);
				has_error = true;
				}
			}
				
			}
			//calling semantic analyzer for function body
		       	semanticAnalyzer(oper1->var.index);
			
			//checking whether return statement present
			if(!hasReturn)
				{
				printf("Error in %d: No return statement for function %s\n",root->lineNo,oper1->var.name);
				has_error=true;
				}
			//Resetting sTable and lTable
			lTable = NULL;
			sTable = NULL;
			hasReturn = false;
			break;
			}
		case 'f':
			{
			
			sTableEntry = LookUp(oper1->var.name);
			
			if(!sTableEntry)
			{
			printf("Error in %d: Function %s not declared\n",root->lineNo,oper1->var.name);
			has_error = true;
			}
			
			else
				{
				//checking whether it is a function(binding set to -1 for functions)
				if(sTableEntry->binding!=-1)
				{
				printf("Error in %d: %s is not a function\n",root->lineNo,oper1->var.name);
				has_error = true;
				break;
				}
				
				//checking whether func is defined
				if(sTableEntry->size ==0)
				{
				printf("Error in %d: %s is not defined\n",root->lineNo,oper1->var.name);
				has_error = true;
				}
				root->type = sTableEntry->type;
				
				if(sTableEntry->args)
				{
				ArgList * funcArgList = oper1->var.argList;
				ArgList * symArgList = sTableEntry->args;
				
				while(symArgList!=NULL&&funcArgList!=NULL)
				{
					//checking whether variables in arglist are declared 
					if(funcArgList->name)
					{
					lTableEntry = LLookUp(funcArgList->name,lTable);
					if(lTableEntry)
						funcArgList->type = lTableEntry->type;
					else
						{
						sTableEntry = LookUp(funcArgList->name);
						if(sTableEntry)
							funcArgList->type = sTableEntry->type;

						else
							{
							printf("Error in %d: %s not declared\n",root->lineNo,funcArgList->name);
							has_error=true;
							}
						}
					}
					//checking whether type matches
					if(symArgList->type!=funcArgList->type)
					{
					
					printf("Error in %d: Type mismatch in arguments of function %s\n",root->lineNo,oper1->var.name);
					has_error =true;
					}

					//setting whether ref or not
					funcArgList->ref = symArgList->ref;

				symArgList = symArgList->next;
				funcArgList = funcArgList->next;
				}
				//checking whether no. of arguments match
				if(symArgList!=NULL||funcArgList!=NULL)
				{
				printf("Error in %d: No of arguments doesnt match in function %s\n",root->lineNo,oper1->var.name);
				has_error = true;
				}
				}
			}
			break;
			
			}
		case 'R':
			{

			semanticAnalyzer(oper1);
			if(oper1->type!=sTable->type)
			{
			printf("Error in %d: Return type of function %s doesnt match with its declaration\n",root->lineNo,sTable->name);
			has_error = true;

			}
			hasReturn = true;
			break;
			}
		}
	}
}
}

