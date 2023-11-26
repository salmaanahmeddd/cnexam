/* Declaration Section */
%{
#include <stdio.h>
%}

%name my_parser
%token NUMBER
%token VARIABLE
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

/* Translation Section */
%%
S: E {
    printf("\nEntered arithmetic expression is Valid\n\n");
    return 0;
}
E: E '+' E
 | E '-' E
 | E '*' E
 | E '/' E
 | E '%' E
 | '(' E ')'
 | NUMBER
 | VARIABLE
 ;

%%

void main()
{
    printf("\nEnter any Arithmetic Expression : \n");
    yyparse();
}

int yyerror(void)
{
    printf("\nEntered arithmetic expression is Invalid\n\n");
}
