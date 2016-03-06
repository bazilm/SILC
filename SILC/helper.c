#include "y.tab.h"

//initializes the output file(adds library code and sets up stack)
void initializeOutputFile(FILE * out)
{
fprintf(out,"START\n");
fprintf(out,"MOV BP,1535\n");
fprintf(out,"MOV SP,BP\n");
fprintf(out,"MOV [0],996\n");
fprintf(out,"MOV [1],2\n");
fprintf(out,"MOV [2],0\n");
fprintf(out,"MOV [3],996\n");
fprintf(out,"MOV [1000],2\n");
fprintf(out,"CALL main\n");
fprintf(out,"HALT\n");

FILE * lib = fopen("library.out","r");
if(!lib)
	{
	printf("Library File Not FOund\n");
	exit(0);
	}
char c = fgetc(lib);

while (c != EOF)
{
fputc(c, out);
c = fgetc(lib);
}

}
//initializes symbol Table
void initializeSymbolTable()
{
//putting main
STable * sTable = malloc(sizeof(STable));
sTable->name = malloc(sizeof("main"));
strcpy(sTable->name,"main");
sTable->type = INT;
sTable->size = 0;			//size set to 0 to denote not defined functions
sTable->binding = -1;			//binding set to -1 for functions
sTable->next= NULL;
sTableBeg = sTable;
sTableEnd = sTable;

}


//initializes type table with int and boolean
void initializeTypeTable()
{
TypeTable * typeTableEntry = malloc(sizeof(TypeTable));
char * name = "int";
typeTableEntry->name = malloc(sizeof(name));
strcpy(typeTableEntry->name,name);
typeTableEntry->members = NULL;
typeTableEntry->size = 1;
typeTableEntry->next = NULL;

typeTableBeg = typeTableEntry;
INT = typeTableEntry;

name = "boolean";
typeTableEntry = malloc(sizeof(TypeTable));
typeTableEntry->name = malloc(sizeof(name));
strcpy(typeTableEntry->name,name);
typeTableEntry->members = NULL;
typeTableEntry->size = 1;
typeTableEntry->next = NULL;

typeTableBeg->next = typeTableEntry;
BOOLEAN = typeTableEntry;
typeTableEnd = typeTableEntry;
}

//installs the type definition to type table
void typeTableInstall(char * name)
{
TypeTable * typeTableEntry = malloc(sizeof(TypeTable));
typeTableEntry->name = malloc(sizeof(name));
strcpy(typeTableEntry->name,name);

LTable * lTable = lTableBeg;
TypeTableId * id,*idBeg,*idEnd;
int binding = 0;
while(lTable)
{
	id = malloc(sizeof(TypeTableId));
	id->name = malloc(sizeof(lTable->name));
	strcpy(id->name,lTable->name);
	id->type = lTable->type;
	id->binding = binding;
	id->pointer = lTable->pointer;
	id->next = NULL;
	if(lTable->pointer)
		binding+=1;
	else
		binding += lTable->type->size;
	
	if(!idBeg)
	{
	idBeg = id;
	idEnd = id;
	}
	else
	{
	idEnd->next = id;
	idEnd = id;
	}
	lTable = lTable->next;
}

//adding the members to typeTableEntry
typeTableEntry->members = idBeg;
typeTableEntry->next = NULL;
typeTableEntry->size = binding;

//adding the type to typetable
typeTableEnd->next = typeTableEntry;
typeTableEnd = typeTableEntry;

//setting back lTableBeg to NULL
lTableBeg = NULL;
fmem = 1;
}

//outputs the type table
void showTypeTable()
{
TypeTable * typeTableEntry = typeTableBeg;

while(typeTableEntry)
{
printf("%s\n",typeTableEntry->name);
TypeTableId * id = typeTableEntry->members;
while(id)
	{
	printf("\t%s - %s - %d\n",id->name,id->type->name,id->binding);
	id=id->next;
	}
typeTableEntry = typeTableEntry->next;
printf("\n\n");
}

}

//looks up in a typetable entry for an id name
TypeTable * TLookUp(char * name,TypeTable * typeTable)
{
TypeTableId * members = typeTable->members;
while(members)
{
if(strcmp(name,members->name)==0)
	return members->type;
members = members->next;
}
return NULL;
}

//gets relative binding of a variable in a type
int getBinding(char * name,TypeTable * typeTable)
{
TypeTableId * members = typeTable->members;
while(members)
{
	if(strcmp(name,members->name)==0)
		return members->binding;
members = members->next;
}
return 0;
}

//checks whether identifier is a type
TypeTable * isType(char * name)
{
TypeTable *beg = typeTableBeg;
while(beg)
{
 if(strcmp(beg->name,name)==0)
	return beg;

 beg = beg->next;
}
return NULL;
}

//adds a list of variables to symbol Table
void makeSTable(IdList * root,TypeTable * type)
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
			{GInstall(idListEntry->name,type,idListEntry->size,idListEntry->argList,idListEntry->ref,idListEntry->pointer,idListEntry->array);
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



STable *GInstall(char *name,TypeTable *type,int size,ArgList * argList,int func,int pointer,int array)
{
STable *sTable = malloc(sizeof(STable));
sTable->name = name;
sTable->type = type;
sTable->pointer = pointer;
sTable->array = array;
//Putting the arguments to local symbol table
if(func)
{
sTable->args = argList;
sTable->size = 0;
sTable->binding = -1;					//func have binding -1
LTable *end,*LTableEntry;
int bind=-(type->size+1);				//binding of args depends on the return type
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
	bind-=argList->type->size;
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

	
	argList = argList->next;
	}

}

//setting binding for global variables
if(!func)
{
sTable->size = type->size * size;
sTable->binding = mem;
if(sTable->pointer)
mem+=1;
else
mem+=(type->size * size);
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

void makeLTable(IdList *root,TypeTable * type)
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
			{LInstall(idListEntry->name,idListEntry->pointer,type);
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
LTable *LInstall(char *name,int pointer,TypeTable *type)
{
LTable *lTable = malloc(sizeof(LTable));
lTable->name = name;
lTable->type = type;
lTable->pointer = pointer;
lTable->size = type->size;
lTable->binding = fmem;
if(pointer)
fmem+=1;
else
fmem+=type->size;

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
IdList * makeIdList(IdList * idListLeft,char * name,TypeTable *type,int size,ArgList * arglist,int ref,int pointer,int array)
{
IdList * idList = malloc(sizeof(IdList));
idList->name = name;
idList->type = type;
idList->size = size;
idList->argList=arglist;
idList->ref=ref;
idList->pointer = pointer;
idList->array = array;
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
ArgList * makeArgList(ArgList * argList,IdList * idList, TypeTable *type)
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

Node * makeFuncNode(TypeTable *type,char * name,ArgList * argList,Node * func_body)
{
if(strcmp(name,"main")==0)
	has_main=true;

if(LookUp(name)==NULL)
{
printf("Error in %d: Function %s not declared\n",lineNo,name);
has_error=true;
return NULL;
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

Node * makeConNode(TypeTable *type,int value)
{

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}

p->nodeType = CONSTANT;
p->type = type;
p->con.value = value;
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
p->type = NULL;
p->var.name = malloc(sizeof(name));
strcpy(p->var.name,name);
p->var.index=index;
p->var.argList = argList;
p->var.innerId = NULL;
p->var.size = size;
p->lineNo=lineNo;
return p;
}

//Adds inner id to a variable
Node * addInnerId(Node * var,char * name)
{
Node * beg = var;
while(beg->var.innerId)
{
beg = beg->var.innerId;
}
beg->var.innerId = makeVarNode(name,NULL,NULL,0);
return var;
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
printf("%s - %d\n",beg->name,beg->binding);
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


