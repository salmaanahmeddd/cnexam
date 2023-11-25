%{
/* program to recognize a C program */
int COMMENT=0;
int cnt=0;
#define ASSIGN_OP 257
#define SEMICOLON 258
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* { printf("\n%s is a PREPROCESSOR DIRECTIVE",yytext);}
int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto {printf("\n\t%s is a KEYWORD",yytext);}
"/*" {COMMENT = 1;}
"*/" {COMMENT = 0; cnt++;}
{identifier}\( {if(!COMMENT)printf("\n\nFUNCTION\n\t%s",yytext);}
\{ {if(!COMMENT) printf("\n BLOCK BEGINS");}
\} {if(!COMMENT) printf("\n BLOCK ENDS");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n %s IDENTIFIER",yytext);}
\".*\" {if(!COMMENT) printf("\n\t%s is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n\t%s is a NUMBER",yytext);}
\)(\;)? {if(!COMMENT) { printf("\n\t%s", yytext); return SEMICOLON; }}
\( {if(!COMMENT) { printf("\n\t%s is an ASSIGNMENT OPERATOR", yytext); return ASSIGN_OP; }}
\<= |\>= |\< |== |\> {if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR",yytext);}

%%

int main(int argc, char **argv)
{
    FILE *file;
    file = fopen("ex2.y", "r");
    if (!file)
    {
        printf("Could not open the file 'var.c'\n");
        exit(0);
    }
    yyin = file;
    yylex();
    printf("\n");
    fclose(file);  // Close the file after reading
    return 0;
}


int yywrap()
{
    return(1);
}
