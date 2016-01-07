typedef enum  {CONSTANT,OPERATOR,VARIABLE} NodeType ;

typedef struct 
{
int value;
}ConNode;

typedef struct 
{
int id;
}VarNode;

typedef struct 
{
char * op;
int nops;
struct NodeTag *operands;
}OperNode;

typedef struct NodeTag
{
NodeType nodeType;

union
{
ConNode con;
OperNode oper;
VarNode var;
};

}Node;

Node * makeConNode(int);
Node * makeVarNode(int);
Node * makeOperNode(char *,int,...);
Node * freeNode(Node *);






