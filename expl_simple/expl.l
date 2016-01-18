%{
#include<stdlib.h>
#include "y.tab.h"
extern int lineNo;
%}

digits	[0-9]
alphabets [a-zA-Z]
identifiers {alphabets}({alphabets}|{digits})*

%%

decl		return DECL;
enddecl		return ENDDECL;
int		return INTEGER;
string		return STR;
{digits}+	{yylval.ival = atoi(yytext);
		return CONST;
		}

[-+*/;]		{return *yytext;}
"=="		return EQ;
"<="		return LE;
">="		return GE;
"!="		return NE;
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
\".+\"		{
		yylval.nval = makeConNode(0,yytext);
		return STRCONST;
		}
{identifiers}	{
		yylval.nval = makeVarNode(yytext);
		return VAR;}

[ \t]
\n		lineNo++;		

.		return *yytext;	

			

%%

int yywrap()
{
return 1;
}

							



