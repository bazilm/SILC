#include "y.tab.h"

void makeSTable(IdList * root,Type type)
{
STable * sTableEntry;

IdList * idListEntry = root;

while(idListEntry!=NULL)
{

	sTableEntry = LookUp(idListEntry->name);
	if(!sTableEntry)
		{
		
		if(idListEntry->size<1)
			{
			printf("Error : Cant have size less than 1\n");
			has_error=true;
			}
		else
			{GInstall(idListEntry->name,type,idListEntry->size,idListEntry->argList,idListEntry->ref);
			idListEntry = idListEntry->next;
			}
		
		}
	else
		{
		printf("Error: Multiple Declarations for %s\n",idListEntry->name);
		has_error=true;
		idListEntry = idListEntry->next;
		}
	
}

}



STable *GInstall(char *name,Type type,int size,ArgList * argList,int func)
{
STable *sTable = malloc(sizeof(STable));
sTable->name = name;
sTable->type = type;

//Putting the arguments to local symbol table
if(func)
{
sTable->args = argList;
sTable->size = 0;
sTable->binding = -1;					//func have binding -1
LTable *end,*LTableEntry;
int bind=-3;
while(argList!=NULL)
	{
	LTableEntry = malloc(sizeof(LTable));
	if(LLookUp(argList->name,sTable->symbolTable))
		{
		printf("Error in %d: Multiple declarations for %s\n",lineNo,argList->name);
		has_error=true;
		}
	LTableEntry->name = malloc(sizeof(argList->name));
	strcpy(LTableEntry->name,argList->name);
	LTableEntry->type = argList->type;
	LTableEntry->size = 1;
	LTableEntry->binding = bind;
	LTableEntry->ref = argList->ref;
	LTableEntry->next = NULL;
	
	if(sTable->symbolTable==NULL)
		{
		sTable->symbolTable = LTableEntry;
		end = LTableEntry;
		}
	else
		{
		end->next = LTableEntry;
		end = end->next;
		}

	bind--;
	argList = argList->next;
	}
}


//setting binding for global variables
switch(type)
{
	case INT:
		{
		if(!func)
		{
		sTable->size = size;
		sTable->binding = mem;
		mem+=size;
		}
		break;
		}

	
	case BOOLEAN:
		{
		if(!func)
		{
		sTable->size=size;
		sTable->binding = mem;
		mem+=size;
		}
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

void makeLTable(IdList *root,Type type)
{
LTable * lTableEntry;
IdList * idListEntry = root;

while(idListEntry!=NULL)
{

	lTableEntry = LLookUp(idListEntry->name,lTableBeg);
	if(!lTableEntry)
		{
		
		if(idListEntry->size<1)
			{
			printf("Error : Cant have size less than 1\n");
			has_error=true;
			}
		else
			{LInstall(idListEntry->name,type,idListEntry->size);
			idListEntry = idListEntry->next;
			}
		
		}
	else
		{
		printf("Error: Multiple declarations for %s \n",idListEntry->name);
		has_error=true;
		idListEntry = idListEntry->next;
		}
	
}

}

//installs in the local symbol table
LTable *LInstall(char *name,Type type,int size)
{
LTable *lTable = malloc(sizeof(LTable));
lTable->name = name;
lTable->type = type;

switch(type)
{
	case INT:
		{
		lTable->size = size;
		lTable->binding = fmem;
		fmem+=size;
		break;
		}

	
	case BOOLEAN:
		{
		lTable->size=size;
		lTable->binding = fmem;
		fmem+=size;
		break;
		}
}

lTable->next = NULL;

if(lTableBeg==NULL)
	{
	lTableBeg=lTable;
	lTableEnd=lTable;
	}
else
	{
	lTableEnd->next = lTable;
	lTableEnd = lTable;
	}
return lTableEnd;
}

//looks up in the passed local symbol table
LTable * LLookUp(char * name,LTable * lTable)
{

while(lTable!=NULL)
	{
	if(strcmp(lTable->name,name)==0)
		return lTable;

	lTable=lTable->next;
	}
return NULL;
}

//makes idlist of a certain type
IdList * makeIdList(IdList * idListLeft,char * name,Type type,int size,ArgList * arglist,int ref)
{
IdList * idList = malloc(sizeof(IdList));
idList->name = name;
idList->type = type;
idList->size = size;
idList->argList=arglist;
idList->ref=ref;
if(idListLeft)
	{IdList * idListEntry = idListLeft;
	while(idListEntry->next !=NULL)
		idListEntry = idListEntry->next;
	
	idListEntry->next = idList;
	return idListLeft;
	}

return idList;
}

	
//makes arglist for func def and func decl of a certain type
ArgList * makeArgList(ArgList * argList,IdList * idList, Type type)
{
ArgList * argListRight,*argListBeg=NULL,*argListEntry;

while(idList != NULL)
{
	
	argListEntry = malloc(sizeof(ArgList));
	argListEntry->name = malloc(sizeof(idList->name));
	strcpy(argListEntry->name,idList->name);
	
	argListEntry->type = type;
	argListEntry->value = 0;
	argListEntry->ref = idList->ref;
	
	if(argListBeg == NULL)
		{
		
		argListBeg = argListEntry;
		argListRight = argListEntry;
		}
	else
		{
		
		argListRight->next = argListEntry;
		argListRight = argListEntry;
		
		}
	idList = idList->next;
	
}

if(argList)
{

argListRight = argList;
while(argListRight->next !=NULL)
	argListRight = argListRight->next;

argListRight->next = argListBeg;
return argList;
}

return argListBeg;
}

//joins arg lists in func def and func decl	
ArgList * joinArgList(ArgList * left,ArgList * right)
{
ArgList * argListEntry = left;
while(argListEntry->next!=NULL)
{
argListEntry=argListEntry->next;
}

argListEntry->next = right;
return left;
}

//makes function call list
ArgList * makeCallList(ArgList * left,Node * value)
{
ArgList *argListEntry = malloc(sizeof(ArgList));
argListEntry->value = value;
argListEntry->next = NULL;

if(left!=NULL)
{
ArgList * end = left;
while(end->next!=NULL)
	end=end->next;

end->next = argListEntry;
return left;
}
return argListEntry;
}
/*Constructors for different node types*/

Node * makeFuncNode(Type type,char * name,ArgList * argList,Node * func_body)
{


if(LookUp(name)==NULL)
{
//TODO: Move this out of here
//Putting main to symbol Table
if(strcmp(name,"main")==0)
{
has_main =true;
STable *sTable = malloc(sizeof(STable));
sTable->name = malloc(sizeof(name));
strcpy(sTable->name,name);
sTable->type = INT;
sTable->size = 1;
sTable->binding = -1;
sTable->symbolTable = malloc(sizeof(LTable));
sTable->symbolTable = lTableBeg;
if(sTableEnd)
	{
	sTableEnd->next = sTable;
	sTableEnd=sTableEnd->next;
	sTableEnd->next = NULL;
	}
else
{
	sTableBeg = sTable;
	sTableEnd = sTable;
	sTableEnd->next = NULL;
}


}
else
{
printf("Error in %d: Function %s not declared\n",lineNo,name);
has_error=true;
return NULL;
}
}
else
{
STable *sTable = LookUp(name);
//size set to 1 to denote that func is defined,initially it was set to zero
sTable->size = 1;
LTable *lTable = sTable->symbolTable;
	if(!lTable)
	{
	lTable = malloc(sizeof(LTable));
	lTable = lTableBeg;
	sTable->symbolTable = lTable;
	}
	else
	{
	LTable *lTableEntry;

	lTableEntry = lTable;
	while(lTableEntry->next!=NULL)
		lTableEntry = lTableEntry->next;

	lTableEntry->next = lTableBeg;
	
	}
}
lTableBeg = NULL;
fmem=1;

Node * funcNode = makeVarNode(name,func_body,argList,1);
funcNode->type = type;

return makeOperNode('F',1,funcNode);

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

Node * makeVarNode(char *name,Node *index,ArgList * argList,int size)
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
p->var.argList = argList;
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


if((p->oper.operands = malloc(nops * sizeof(Node)))==NULL)
	{
	printf("No memory\n");
	exit(0);
	}
	
int i=0;
for(i=0;i<nops;i++)
{
Node * temp = va_arg(temp_args,Node *);
if(temp)
	p->oper.operands[i] = *temp;
else
	i--;
}
p->lineNo=lineNo;
p->oper.nops = i;
return p;
}

void showContents(STable * beg)
{

while(beg!=NULL)
{
printf("%s\n",beg->name);
if(beg->symbolTable)
{
	LTable * temp = beg->symbolTable;
	while(temp!=NULL)
		{	
		printf("\t%s  %d\n",temp->name,temp->binding);
		temp=temp->next;
		}
}
	
beg=beg->next;
}
}

void LshowContents(LTable * beg)
{
while(beg!=NULL)
{
printf("%s  %d\n",beg->name,beg->binding);
beg=beg->next;
}
}


