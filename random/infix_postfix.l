%{
#include<stdlib.h>
#include "y.tab.h"
%}

digits [0-9]

%%

{digits}+	{yylval = atoi(yytext);
		return NUM;
		}

[-+*/\n]	{return *yytext;}

[ \t]		
.		{yyerror("Invalid expression");}

%%

int yywrap()
{
return 1;
}

void yyerror(char * s)
{
printf("%s\n",s);
}


