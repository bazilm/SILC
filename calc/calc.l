%{
#include<stdlib.h>
#include "y.tab.h"
%}

digits	[0-9]

%%

{digits}+	{yylval.ival = atoi(yytext);
		return INTEGER;
		}

[-+*/;\n]		{return *yytext;}
[a-z]		{yylval.ival = *yytext - 'a';
		return VAR;}
exit		{return EXIT;}
[ \t]		

.		{return *yytext;}	

			

%%

int yywrap()
{
return 1;
}

							



