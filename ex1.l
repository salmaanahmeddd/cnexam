%{
#include<stdio.h>
%}

%%
bool|int|float|break|continue|while|for|printf|scanf|d|if|then|else|char printf("Keyboard \n");
[-+*/]+ printf("Operators \n");
[0-9]+ printf("Number \n");
[@#$*!&]+ printf("Special Character \n");
['".,]+ printf("Punctuation Character \n");
[A-Za-z0-9]+ printf("Identifier \n");
%%

int main(){
yylex();
}
