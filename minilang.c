#include <stdio.h>
#include <string.h>
#include "minilang.h"

extern int yylex();
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

int main(int argc, char *argv[])
{
    FILE *inputFile = fopen("input.txt", "r");
    
    if (!inputFile)
    {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return 1;
    }

    yyin = inputFile;

    int token = yylex();

    while (token)
    {
        switch (token)
        {
        case DATATYPE:
            printf("[DATATYPE]\t\t");
            break;

        case KEYWORD:
            printf("[KEYWORD]\t\t");
            break;

        case OPERATOR:
            printf("[OPERATOR]\t\t");
            break;

        case IDENTIFIER:
            printf("[IDENTIFIER]\t\t");
            break;

        case INT_LITERAL:
            printf("[INT_LITERAL]\t\t");
            break;

        case BOOL_LITERAL:
            printf("[BOOL_LITERAL]\t\t");
            break;

        case COMMENT:
            printf("[COMMENT]\t\t");
            break;

        case PARENTHESIS:
            printf("[PARENTHESIS]\t\t");
            break;

        default:
            break;
        }

        printf("%s\n", yytext);

        token = yylex();
    }
}
