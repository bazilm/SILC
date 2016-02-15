#include<stdbool.h>
#include<stdarg.h>

typedef enum  {CONSTANT,OPERATOR,VARIABLE} NodeType ;
typedef enum  {INT,BOOLEAN} Type;

typedef struct
{
char * name;
Type type;
int value;
int ref;
}Arglist;

typedef struct LSymTable
{
char * name;
Type type;
int binding;
struct LSymTable * next;
}LTable;

typedef struct SymTable
{
char * name;
Type type;
int size;
int binding;
Arglist * args;
LTable * symbolTable;
struct SymTable * next;
}STable;

typedef struct IDList
{
char * name;
Type type;
int size;
ArgList * argList;
int ref;

}Idlist;

typedef struct 
{

int value;

}ConNode;

typedef struct 
{
char * name;
struct NodeTag *index;
ArgList * argList;
int size;
}VarNode;

typedef struct 
{
int op;
int nops;
struct NodeTag *operands;
}OperNode;

typedef struct NodeTag
{
NodeType nodeType;
Type type;
int lineNo;
union
{
ConNode con;
OperNode oper;
VarNode var;
};

}Node;

Node * makeConNode(Type,int);
Node * makeVarNode(char *,Node *,int);
Node * makeOperNode(int,int,...);
int interpret(Node *);
void semanticAnalyzer(Node *);
void freeNode(Node *);

void makeSTable(Node *,Type);
STable * GInstall(char *,Type,int);
STable * LookUp(char *);

void makeLTable(Node *,Type);
LTable * LInstall(char *,Type,int);
LTable * LookUp(char *);

void AddArg(char *,Type,int,int);

Idlist * makeIdList(char *,Type,Arglist ,int);

void setVariableValue(char * name,Node * index);
void getVariableValue(char * name,Node * index);





