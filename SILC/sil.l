%{
#include<stdlib.h>
#include "y.tab.h"
extern int lineNo;
%}

digits	[0-9]
alphabets [a-zA-Z]
identifiers {alphabets}({alphabets}|{digits})*

%%
typedef		return TYPEDEF;
decl		return DECL;
enddecl		return ENDDECL;
{digits}+	{yylval.ival = atoi(yytext);
		return CONST;
		}
"true"		{yylval.ival = 1;return TRUE;}
"false"		{yylval.ival = 0;return FALSE;}
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
"return"	return RET;
new		return NEW;
free		return FREE;
\".+\"		{
		yylval.sval = malloc(sizeof(yytext));
		strncpy(yylval.sval,yytext+1,strlen(yytext)-2);
		return STRCONST;
		}
{identifiers}	{
		if(isType(yytext))
			{
			yylval.typeTable = isType(yytext);
			return TYPE;
			}
		else
			{
			yylval.sval =malloc(sizeof(yytext));
			strcpy(yylval.sval,yytext);
			return VAR;
			}
		}

[ \t]
\n		lineNo++;		

.		return *yytext;	

			

%%

int yywrap()
{
return 1;
}

							



