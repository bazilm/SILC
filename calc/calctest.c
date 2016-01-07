#include<stdio.h>
#include<stdarg.h>
#include "calc.h"


int main()
{
Node * node1, * node2, * node3;
int i,j;
char oper;
scanf("%d\n%d\n%c",&i,&j,&oper);

node1 = makeConNode(i);
node2 = makeConNode(j);
node3 = makeOperNode(&oper,2,node1,node2);
printf("%d\n",node3->oper.nops);

for(i =0;i<node3->oper.nops;i++)
{
printf("%d\t",node3->oper.operands[i].con.value);
}
return 0;
}


Node * makeConNode(int value)
{
Node * p;
p = malloc(sizeof(Node *));

p->nodeType = CONSTANT;
p->con.value = value;
return p;
}

Node * makeVarNode(int id)
{
Node *p;
p = malloc(sizeof(Node *));

p->nodeType = VARIABLE;
p->var.id = id;
return p;
}

Node * makeOperNode(char * oper,int nops,...)
{
va_list temp_args;
va_start(temp_args,nops);

Node * p;
p = malloc(sizeof(Node*));

p->nodeType = OPERATOR;
p->oper.op = oper;
p->oper.nops = nops;

p->oper.operands = malloc(nops * sizeof(Node*));
int i=0;
for(i=0;i<nops;i++)
{
p->oper.operands[i] = *va_arg(temp_args,Node*);
}

return p;
}



