

%{

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void yyerror(char *);
#define YYSTYPE float
float var[26];
%}


%token INTEGER VARIABLE
%token END

%left '+' '-'
%left '*' '/'
%left '^'
%%

program: 
	 program statement '\n'	
     	 |error '\n'
	 |
	 ;


statement:	expr				{printf("The result is %g\n",$1);}
		|'(' VARIABLE '=' expr ')'	{var[(int)$2] = $4;}	
		|VARIABLE '=' expr		{var[(int)$1] = $3;}
		
		;
expr:	
	 INTEGER			{$$ = $1;}
	|VARIABLE			{$$ = var[(int)$1];}
	|'(' expr '+' expr ')'		{$$ = $2 + $4;}
	|'(' expr '-' expr ')'		{$$ = $2 - $4;}
	|'(' expr '*' expr ')' 		{$$ = $2 * $4;}
	|'(' expr '/' expr ')'		{$$ = $2 / $4;}
	
	|expr '*' expr 			{$$ = $1 * $3;}
	|expr '+' expr			{$$ = $1 + $3;}
	|expr '-' expr			{$$ = $1 - $3;}
	|expr '/' expr			{$$ = $1 / $3;}
	|END				{return 0;}
	;


%%

void yyerror(char * s)
{
fprintf(stderr,"%s\n",s);
}

int main(void)
{
yyparse();
return 0;
}



