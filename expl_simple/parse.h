#include<stdbool.h>
#include<stdarg.h>

typedef enum  {CONSTANT,OPERATOR,VARIABLE} NodeType ;
typedef enum  {INT,BOOLEAN} Type;

typedef struct SymTable
{
char * name;
Type type;
int size;
void * binding;
struct SymTable * next;
}STable;


typedef struct 
{

int value;

}ConNode;

typedef struct 
{
char * name;
struct NodeTag *index;
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
Node * makeVarNode(char *,Node *);
Node * makeOperNode(int,int,...);
int interpret(Node *);
void semanticAnalyzer(Node *);
void freeNode(Node *);

void makeSTable(Node *,Type);
STable * GInstall(char *,Type,int);
STable * LookUp(char *);

void setVariableValue(char * name,Node * index,Node * value);
int getVariableValue(char * name,Node * index);





