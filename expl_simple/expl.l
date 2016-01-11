%{
#include<stdlib.h>
#include "y.tab.h"
extern int lineNo;
%}

digits	[0-9]

%%

{digits}+	{yylval.ival = atoi(yytext);
		return INTEGER;
		}

[-+*/;]	{return *yytext;}
[a-z]		{yylval.cval = *yytext;
		return VAR;}
\=\=		return EQUALS;
\<\=		return LE;
\>\=		return GE;
read		return READ;
write		return WRITE;
BEGIN		return BEG;
END		return END;
if		return IF;
then		return THEN;
else		return ELSE;
ENDIF		return ENDIF;

[ \t]
\n		lineNo++;		

.		return *yytext;	

			

%%

int yywrap()
{
return 1;
}

							



