%{
#include<stdio.h>
%}

%token NUM

%left '+' '-'
%left '*' '/'



%%

program: program expr '\n'	{printf("\n");
				printf("= %d\n>>",$2);}	
	|error '\n'
	|		
	;

expr:
	 expr '+' expr	{printf("+ ");
			$$ = $1 + $3;
			}
	|expr '-' expr  {printf("- ");
			$$ = $1 - $3;
			}
	|expr '*' expr  {printf("* ");
			$$ = $1 * $3;}
	|expr '/' expr  {printf("/ ");
			$$ = $1 / $3;}
	|NUM		{printf("%d ",$1);}
	;

%%

int main()
{
yyparse();
return 0;
}





