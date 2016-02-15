#include "y.tab.h"


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


void compile(Node * root)
{

STable * sTableEntry;
int res1,res2,res3;
int nops;
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
				//return interpret(oper1)&&interpret(oper2);
				break;
				}

			case OR:
				{
				//return interpret(oper1)||interpret(oper2);
				break;
				}

			case NOT:
				{
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

			case '$':
				{
				compile(oper1);
				compile(oper2);
				break;

				}
		}
	}

}
}



