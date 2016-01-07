digits		[0-9]\.?[0-9]*
char	[a-z]
%{
#define YYSTYPE float
#include<stdlib.h>
#include<math.h>
#include"y.tab.h"
void yyerror(char *);
%}

%%
{digits}+	{yylval = atof(yytext);
		
		 return INTEGER;
		}

{char}		{
		 yylval = *yytext - 'a';
		 return VARIABLE;
		}
[-+*/()=\na]	return *yytext;

[ \t]    	;

exit		return END;
.		yyerror("Invalid character");

%%

int yywrap(void)
{
return 1;
}

	
