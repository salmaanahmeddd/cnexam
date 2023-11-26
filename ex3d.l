%{
/* Definition section */
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}

/* Rule Section */
%%
[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}
[\t]       ; /* Ignore tabs */
[\n]       return 0; /* Ignore newlines */
.         return yytext[0]; /* Match any other character */
%%

int yywrap() {
    return 1;
}
