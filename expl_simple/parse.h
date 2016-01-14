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
union
{
ConNode con;
OperNode oper;
VarNode var;
};

}Node;

Node * makeConNode(int);
Node * makeVarNode(char *);
Node * makeOperNode(int,int,...);
int interpret(Node *);
void freeNode(Node *);

STable * GInstall(char *,Type,int);
STable * LookUp(char *);

extern int *sym[26];




