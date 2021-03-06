#include<stdbool.h>
#include<stdarg.h>

typedef enum  {CONSTANT,OPERATOR,VARIABLE} NodeType ;

typedef struct typetable TypeTable;
typedef struct  typetableid
{
char * name;
TypeTable * type;
int binding;
int pointer;
struct typetableid * next;
}TypeTableId;

typedef struct typetable
{
char * name;
TypeTableId * members;
int size;
struct typetable * next;
}TypeTable;

typedef struct 
{
int value;
}ConNode;

typedef struct 
{
char * name;
struct NodeTag *index;
struct ArgList *argList;
struct NodeTag *innerId;
int size;
int pointer;
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
TypeTable *type;
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
TypeTable *type;
Node * value;
int ref;
struct ArgList * next;
}ArgList;


typedef struct LSymTable
{
char * name;
TypeTable *type;
int size;
int binding;
int pointer;
int ref;
struct LSymTable * next;
}LTable;

typedef struct SymTable
{
char * name;
TypeTable *type;
int size;
int binding;
int pointer;
int array;
ArgList * args;
LTable * symbolTable;
struct SymTable * next;
}STable;

typedef struct IdList
{
char * name;
TypeTable *type;
int size;
ArgList * argList;
int ref;
int pointer;
int array;
struct IDList * next;
}IdList;


//function declarations
Node * makeConNode(TypeTable *,int);
Node * makeVarNode(char *,Node *,ArgList *,int);
Node * addInnerId(Node *,char *);
Node * makeOperNode(int,int,...);

int interpret(Node *);
void semanticAnalyzer(Node *);
void freeNode(Node *);

void initializeTypeTable();
void typeTableInstall();
TypeTable *TLookUp(char *,TypeTable *);
int getBinding(char *,TypeTable *);

void initializeSymbolTable();
void makeSTable(IdList *,TypeTable *);
STable * GInstall(char *,TypeTable *,int,ArgList *, int,int,int);
STable * LookUp(char *);

void makeLTable(IdList *,TypeTable *);
LTable * LInstall(char *,int,TypeTable *);
LTable * LLookUp(char *,LTable *);

ArgList * makeCallList(ArgList *,Node *);

IdList * makeIdList(IdList *,char *,TypeTable *,int,ArgList *,int,int,int);

void setVariableValue(Node * ,Node * );
void getVariableValue(Node * ,Node * );

void showContents(STable *);
void LshowContents(LTable *);
void showTypeTable();

void initializeOuputFile(FILE *);

//global variables
STable *sTableBeg=NULL,*sTableEnd;
LTable *lTableBeg=NULL,*lTableEnd;
IdList * idListBeg=NULL, *idListEnd;
TypeTable *typeTableBeg=NULL,*typeTableEnd;
TypeTable *INT,*BOOLEAN;
Node * root;
int lineNo;
bool has_error = false,has_main=false;
FILE * out;
int reg_count=-1;
int mem = 1001,if_count=1,while_count=1,fmem=1;



