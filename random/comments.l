%{
#include<stdio.h>
%}

scomment \/\/
mcommentbeg	\/\*
mcommentend	\*\/

%%

{scomment}.*		{printf("%s\n",yytext);}

{mcommentbeg}[^(*/)]*{mcommentend}	{printf("%s\n",yytext);}

[^(/*)(//)(*/)]*|(\(|\))*|\*	{}
{mcommentbeg}|{mcommentend}		{}


%%

int main()
{
FILE * file = fopen("lex.yy.c","r");
yyin = file;
yylex();
return 0;
}

int yywrap()
{
return 1;
}
