#include "y.tab.h"

void setVariableValue(char *name,Node *index)
{
LTable *lTableEntry = LLookUp(name,lTable);
//if not in local table find in global table
if(!lTableEntry)
	{
	STable *sTableEntry = LookUp(name);
	
	if(!index)
	{
	reg_count++;
	fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
	}
	//get the value of the index
	else
	{
	compile(index);
	reg_count++;
	fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
	fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
	reg_count--;
	}
	}
else
 	{
	reg_count++;
	fprintf(out,"MOV R%d,BP\n",reg_count);
	reg_count++;
	fprintf(out,"MOV R%d,%d\n",reg_count,lTableEntry->binding);
	fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
	reg_count--;
	//if it is a reference variable,get the address it is storing
	if(lTableEntry->ref==1)
		fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
	
	}
}

void getVariableValue(char *name,Node *index)
{
LTable *lTableEntry = LLookUp(name,lTable);
if(!lTableEntry)
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
else
	{
	reg_count++;
	fprintf(out,"MOV R%d,BP\n",reg_count);
	reg_count++;
	fprintf(out,"MOV R%d,%d\n",reg_count,lTableEntry->binding);
	fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
	reg_count--;
	fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
	
	if(lTableEntry->ref ==1)
		fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
	}
}

ArgList * reverseArgList(ArgList * argList)
{
ArgList * argLists[100],*revArgList=NULL;
int count=0;
ArgList * temp = argList;
//getting the args in an array to reverse
while(temp!=NULL)
	{
	argLists[count] = temp;
	count++;
	temp=temp->next;
	}

//traversing the array in the reverse order to get the reversed argList
for(count=count-1;count>=0;count--)
{
	if(!revArgList)
	{
	revArgList = argLists[count];
	temp = revArgList;
	}
	else
	{
	temp->next = argLists[count];
	temp = temp->next;
	temp->next=NULL;
	}

}

return revArgList;
}



void compile(Node * root)
{

STable * sTableEntry;
LTable * lTableEntry;
ArgList * argListEntry;
int res1,res2,res3;
int nops,i;
Node *oper1,*oper2,*oper3;

switch(root->nodeType)
	{
	case CONSTANT:
		{
		reg_count++;
		fprintf(out,"MOV R%d,%d\n",reg_count,root->con.value);
		break;
		}

	case VARIABLE:
		{
		getVariableValue(root->var.name,root->var.index);
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
				compile(oper2);
				fprintf(out,"PUSH R%d\n",reg_count);
				reg_count--;
				compile(oper1);
				reg_count++;
				fprintf(out,"POP R%d\n",reg_count);
				fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;
				}

			case '-':
				{
				if(nops==1)
					{
					compile(oper1);
					fprintf(out,"MOV R%d,0\n",reg_count);
					fprintf(out,"MUL R%d,R%d\n",reg_count-1,reg_count);
					reg_count--;	
					}
				else
					{
					compile(oper2);
					fprintf(out,"PUSH R%d\n",reg_count);
					reg_count--;
					compile(oper1);
					reg_count++;
					fprintf(out,"POP R%d\n",reg_count);
					fprintf(out,"SUB R%d,R%d\n",reg_count-1,reg_count);
					reg_count--;		
					}
				break;
				}
	
			case '*':
				{
				compile(oper2);
				fprintf(out,"PUSH R%d\n",reg_count);
				reg_count--;
				compile(oper1);
				reg_count++;
				fprintf(out,"POP R%d\n",reg_count);
				fprintf(out,"MUL R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;		
				break;
				}
	
			case '/':
				{
				compile(oper2);
				fprintf(out,"PUSH R%d\n",reg_count);
				reg_count--;
				compile(oper1);
				reg_count++;
				fprintf(out,"POP R%d\n",reg_count);
				fprintf(out,"DIV R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;		
				break;
				}
	
			case '%':
				{
				compile(oper2);
				fprintf(out,"PUSH R%d\n",reg_count);
				reg_count--;
				compile(oper1);
				reg_count++;
				fprintf(out,"POP R%d\n",reg_count);
				fprintf(out,"MOD R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;		
				break;
				}

			case '=':
				{
				
				setVariableValue(oper1->var.name,oper1->var.index);
				
				compile(oper2);
				fprintf(out,"MOV [R%d],R%d\n",reg_count-1,reg_count);
				reg_count-=2;

				break;
				}	
			
			case EQ:
				{
				compile(oper1);
				compile(oper2);
				fprintf(out,"EQ R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;
				}
			case '<':
				{
				compile(oper1);
				compile(oper2);
				fprintf(out,"LT R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;
				}

			case '>':
				{
			
				compile(oper1);
				compile(oper2);
				fprintf(out,"GT R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;
							
				}

			case LE:
				{
				compile(oper1);
				compile(oper2);
				fprintf(out,"LE R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;
				}

			case GE:
				{
			
				compile(oper1);
				compile(oper2);
				fprintf(out,"GE R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;		
				}

			case NE:
				{
				compile(oper1);
				compile(oper2);
				fprintf(out,"NE R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				break;
				}
	
			case AND:
				{
				compile(oper1);
				compile(oper2);
				fprintf(out,"MUL R%d,R%d\n",reg_count-1,reg_count);
				break;
				}

			case OR:
				{
				compile(oper1);
				compile(oper2);
				fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
				fprintf(out,"MOV R%d,0\n",++reg_count);
				fprintf(out,"GT R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				//return interpret(oper1)||interpret(oper2);
				break;
				}

			case NOT:
				{
				compile(oper1);
				fprintf(out,"MOV R%d,-1\n",++reg_count);
				fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
				fprintf(out,"MUL R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;
				//return !interpret(oper1);
				break;
				}
			case READ:
				{
				setVariableValue(oper1->var.name,oper1->var.index);
				reg_count++;
				fprintf(out,"IN R%d\n",reg_count);
				fprintf(out,"MOV [R%d],R%d\n",reg_count-1,reg_count);
				reg_count-=2;
				break;
				}

			case WRITE:
				{
			
				compile(oper1);
				fprintf(out,"OUT R%d\n",reg_count);
				reg_count--;
				break;
				}

			case IF:
			       {
				int cnt = if_count;
				if_count++;
				compile(oper1);
				fprintf(out,"JZ R%d,ELSE%d\n",reg_count--,cnt);
				compile(oper2);
				fprintf(out,"JMP ENDIF%d\n",cnt);
				fprintf(out,"ELSE%d:\n",cnt);
				
				if(root->oper.nops==3)
					compile(oper3);
				fprintf(out,"ENDIF%d:\n",cnt);
				
				
				/*if(interpret(oper1))
					interpret(oper2);
				else if(root->oper.nops==3)
					interpret(oper3);
				*/			
				break;
				}

			case WHILE:
				{
				int cnt = while_count;
				while_count++;
				fprintf(out,"WHILEBEG%d:\n",cnt);
				compile(oper1);
				fprintf(out,"JZ R%d,WHILEEND%d\n",reg_count--,cnt);
				compile(oper2);
				fprintf(out,"JMP WHILEBEG%d\n",cnt);
				fprintf(out,"WHILEEND%d:\n",cnt);
				
				
				//while(interpret(oper1))
				//	interpret(oper2);
				break;
				}

			case 'S':
				{
				compile(oper1);
				compile(oper2);
				break;

				}

			case 'F':
				{
				
				reg_count = -1;
				sTableEntry = LookUp(oper1->var.name);
				//setting lTable to be used by func body
				lTable = sTableEntry->symbolTable;
				
				//Setting a the func name as label for the function
				fprintf(out,"%s:\n",oper1->var.name);

				//Setting up activation record
				fprintf(out,"PUSH BP\n");
				fprintf(out,"MOV BP,SP\n");
				
				//pushing space for the local variables to stack
				if(lTable)
				{
				//local symbol table contains the argList too ,moving past them
				lTableEntry = lTable;
				argListEntry = sTableEntry->args;
				while(argListEntry!=NULL)
					{
					argListEntry = argListEntry->next;
					lTableEntry=lTableEntry->next;
					}
				//pushing space for the local variables
				while(lTableEntry!=NULL)
					{
					fprintf(out,"PUSH R%d\n",++reg_count);
					reg_count--;
					lTableEntry = lTableEntry->next;
					}
				}
				//compiling func body
				compile(oper1->var.index);
	
				//Resetting the stack for the caller function by popping the local variables
				if(lTable)
					{
					lTableEntry = lTable;
					//moving past the arglist variables
					argListEntry = sTableEntry->args;
					while(argListEntry!=NULL)
					{
					argListEntry = argListEntry->next;
					lTableEntry=lTableEntry->next;
					}

					//popping the local variables
					while(lTableEntry!=NULL)
						{
						fprintf(out,"POP R%d\n",++reg_count);
						reg_count--;
						lTableEntry = lTableEntry->next;
						}
					}
				//setting BP back
				fprintf(out,"POP BP\n");
				fprintf(out,"RET\n");
				break;
				}
			case 'f':
				{
				
				//pushing the used registers
				for(i=0;i<=reg_count;i++)
					fprintf(out,"PUSH R%d\n",i);

				
				//pushing the func args
				if(oper1->var.argList)
					{
					//pushing in the reverse order
					
					argListEntry = reverseArgList(oper1->var.argList);

					//making the arglist point to the reversed arglist
					oper1->var.argList = argListEntry;

					while(argListEntry!=NULL)
					{

					//if ref variable find the address and push
					if(argListEntry->ref)
					{
					setVariableValue(argListEntry->value->var.name,NULL);		//gets the address of the variable
					fprintf(out,"PUSH R%d\n",reg_count);
					reg_count--;
					}
					
					//else finding the value of the expression
					else
					{
					compile(argListEntry->value);
					fprintf(out,"PUSH R%d\n",reg_count);
					reg_count--;
					}
					
					argListEntry = argListEntry->next;
					}
					}
				
				//pushing space for the return value (pushing the value 0)
				fprintf(out,"MOV R%d,0\n",0);
				fprintf(out,"PUSH R%d\n",0);

				//calling the function
				fprintf(out,"CALL %s\n",oper1->var.name);
				
				//popping the return value
				reg_count++;
				fprintf(out,"POP R%d\n",reg_count);

				//pop back the arglist
				if(oper1->var.argList)
					{
					argListEntry = oper1->var.argList;
					while(argListEntry!=NULL)
						{
						fprintf(out,"POP R%d\n",0);
						argListEntry=argListEntry->next;
						}
					}

				//popping back the registers
				for(i=reg_count-1;i>=0;i--)
					fprintf(out,"POP R%d\n",i);
				
				break;
				}

			case 'R':
				{

				//getting the address to store the return value i.e BP-2
				fprintf(out,"MOV R%d,BP\n",++reg_count);
				fprintf(out,"MOV R%d,-2\n",++reg_count);
				fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
				reg_count--;

				//compiling the expression for return value
				compile(oper1);
	
				//putting the value in the address
				fprintf(out,"MOV [R%d],R%d\n",reg_count-1,reg_count);
				

				break;
				}
				
			
	}}

}
}



