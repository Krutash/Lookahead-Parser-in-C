/* 
Group 28
Utkarsh Kumar 2017B2A71008P
Suchisattam Saran 2017B2A70585P
Supratik Bhattacharya 2017B2A70745P
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct tokenStream
{
	char token[20];
	char lexeme[20];
	int linenumber;
	struct tokenStream *next;
} tokenStream;

typedef struct data {
	char symbol[20];
	struct data *next;
}data;

typedef data* grammar;
typedef data node;

int x;

typedef struct parseTree
{
	char sym[25];
	int line;
	int term;
	int key;
	int gram;
	struct parseTree *child;
}parseTree;

typedef struct ope {
	char sym[5];
	struct ope *next;
} ope;
typedef struct ope ope;
typedef struct string {
	char term[20];
	struct string *next;
}string;
typedef struct string string;
typedef struct dataEntry {
	int dec;
	int type;
	int sizeofArray;
	ope *list;
	string *stringlist;
}dataEntry;

char * getToken(char *lexeme);
char * stripTab(char *t);
tokenStream * tokeniseSourcecode( char *f, tokenStream *s);
grammar getPoint(grammar G);
grammar readGrammar(FILE *fp, grammar G);
parseTree *createParse(parseTree *t, tokenStream *s, grammar G);
parseTree *createParseTree(parseTree *t, tokenStream *s, grammar G);
