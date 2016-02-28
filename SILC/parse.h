#include<stdbool.h>
#include<stdarg.h>

typedef enum  {CONSTANT,OPERATOR,VARIABLE} NodeType ;
typedef enum  {INT,BOOLEAN} Type;


typedef struct 
{

int value;

}ConNode;

typedef struct 
{
char * name;
struct NodeTag *index;
struct ArgList * argList;
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

typedef struct ArgList
{
char * name;
Type type;
Node * value;
int ref;
struct ArgList * next;
}ArgList;


typedef struct LSymTable
{
char * name;
Type type;
int size;
int binding;
int ref;
struct LSymTable * next;
}LTable;

typedef struct SymTable
{
char * name;
Type type;
int size;
int binding;
ArgList * args;
LTable * symbolTable;
struct SymTable * next;
}STable;

typedef struct IdList
{
char * name;
Type type;
int size;
ArgList * argList;
int ref;
struct IDList * next;
}IdList;


Node * makeConNode(Type,int);
Node * makeVarNode(char *,Node *,ArgList *,int);
Node * makeOperNode(int,int,...);
int interpret(Node *);
void semanticAnalyzer(Node *);
void freeNode(Node *);

void makeSTable(IdList *,Type);
STable * GInstall(char *,Type,int,ArgList *, int);
STable * LookUp(char *);

void makeLTable(IdList *,Type);
LTable * LInstall(char *,Type,int);
LTable * LLookUp(char *,LTable *);

ArgList * makeCallList(ArgList *,Node *);

IdList * makeIdList(IdList *,char *,Type,int,ArgList *,int);

void setVariableValue(char * name,Node * index);
void getVariableValue(char * name,Node * index);


void showContents(STable *);
void LshowContents(LTable *);



