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
\=\=		return EQ;
\<\=		return LE;
\>\=		return GE;
!=		return NE;
and		return AND;
or		return OR;
not		return NOT;
read		return READ;
write		return WRITE;
begin		return BEG;
end		return END;
if		return IF;
then		return THEN;
else		return ELSE;
endif		return ENDIF;
while		return WHILE;
do		return DO;
endwhile 	return ENDWHILE;

[ \t]
\n		lineNo++;		

.		return *yytext;	

			

%%

int yywrap()
{
return 1;
}

							



