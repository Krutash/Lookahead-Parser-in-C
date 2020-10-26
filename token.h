#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
typedef struct token
{
	char token[25];
	char lexeme[25];
	int linenumber;
} token;
*/
typedef struct tokenStream
{
	char token[20];
	char lexeme[20];
	int linenumber;
	struct tokenStream *next;
} tokenStream;

char * getToken(char *lexeme);

char * stripTab(char *t);

tokenStream * tokeniseSourcecode( char *f, tokenStream *s);

