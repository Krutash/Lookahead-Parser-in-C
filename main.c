#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"read.h"

int main(){

	grammar G = getPoint(G);
	FILE *fp = fopen("grammar.txt", "r");
	G = readGrammar(fp, G);
	printf("okay\n");
	
	for(int i = 0; i<x; i++)
	{
		printf("%s\n", G[i].symbol);
		node *nextptr = G[i].next;
		while(nextptr != NULL)
		{
			printf("%s\n", nextptr->symbol);
			nextptr = nextptr->next;
		}
	}
}
