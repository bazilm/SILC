#include "y.tab.h"

void makeSTable(Idlist * root,Type type)
{
STable * sTableEntry;

Idlist * idListEntry = root;

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
			{GInstall(idListEntry->name,idListEntry->type,idListEntry->size,idListEntry->argList,idListEntry->ref);
			idListEntry = idListEntry->next;
			}
		
		}
	else
		{
		printf("Error:Variable %s declared once\n",idListEntry->name);
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
Idlist * idListEntry = root;

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
			{LInstall(idListEntry->name,idListEntry->type,idListEntry->size);
			idListEntry = idListEntry->next;
			}
		
		}
	else
		{
		printf("Error:Variable %s declared once\n",idListEntry->name);
		has_error=true;
		idListEntry = idListEntry->next;
		}
	
}

}


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
		sTable->size=size;
		sTable->binding = fmem;
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

Idlist * makeIdList(Idlist * idListLeft,char * name,Type type,int size,Arglist * arglist,int ref)
{
Idlist * idList = malloc(sizeof(Idlist));
idList->name = name;
idList->type = type;
idList->size = size;
idList->argList=arglist;
idList->ref=ref;
if(idListLeft)
	{Idlist * idListEntry = idListLeft;
	while(idListEntry->next !=NULL)
		idListEntry = idListEntry->next;
	
	idListEntry->next = idList;
	return idListLeft;
	}

return idList;
}

	

ArgList * makeArgList(ArgList * argList,Idlist * idList, Type type)
{
ArgList * argListRight,*argListBeg;

while(idList != NULL)
{
	argListEntry = malloc(sizeof(ArgList));
	strcpy(argListEntry->name,idList->name);
	argListEntry->type = type;
	argListEntry->value = 0;
	argListEntry->ref = idList->ref;
	
	if(argListBeg == NULL)
		{argListBeg = argListEntry;
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
	
void setType(Idlist * idListLeft,Idlist * idListRight,Type type)
{
Idlist * idListPointer = idListRight;
idListBeg = NULL;
idListEnd = NULL;
while(idListPointer!=NULL)
{
	idListPointer->type = type;
	idListPointer = idListPointer->next;
}

if(idListLeft)
	{
	idListPointer = idListLeft;
	while(idListPointer->next!=NULL)
	{
	idListPointer = idListPointer->next;
	}
	idListPointer->next = idListRight;
	return idListLeft;
	}
return idListRight;
}


/*Constructors for different node types*/

Node * makeFuncNode(Type type,char * name,ArgList * argList,Node * func_body)
{
Node * funcNode = makeVarNode(name,func_body,1);
funcNode->type = type;
funcNode->argList = argList;

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

