#include<stdio.h>
#include<string.h>

typedef struct data {
	char symbol[25];
	struct data *next;
}data;

typedef data* grammar;
typedef data node;

int x;

grammar getPoint(grammar G);

grammar readGrammar(FILE *fp, grammar G);
