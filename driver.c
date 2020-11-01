/* 
Group 28
Utkarsh Kumar 2017B2A71008P
Suchisattam Saran 2017B2A70585P
Supratik Bhattacharya 2017B2A70745P
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "def.h"
//#include "read.h"

void printParseTree(parseTree *t)
{
	if(t != NULL)
	{
		char term[5] = "NO";
		char gram[5] = "NA";
		if(t->term)
			strcpy(term, "YES");
		if(t->gram)
		printf("\nSymbol : %s, line : %d, term? : %s, keyword? : %d, Grammar : %d\n",t->sym, t->line, term, t->key, t->gram);
		
		else
		printf("\nlabel : %s, line : %d, term? : %s, keyword? : %d, Grammar : %s\n",t->sym, t->line, term, t->key, gram);
		printParseTree(t->child);
	}
	fflush(stdout);
	return;
}

int main()
{
	tokenStream *s =NULL;
	char filename[20];
	printf("enter name of test case file (example : t1.txt): ");
	scanf("%s",&filename);
	s = tokeniseSourcecode(filename, s);
	tokenStream *ptr = s;
	grammar G = getPoint(G);
	FILE *fp2 = fopen("group_28_grammar.txt", "r");
	G = readGrammar(fp2, G);
	parseTree *t = NULL;
	int option = 1;
	while(option != 0){
		printf("\nprovide options for the file (0-4): ");
		scanf("%d", &option);
		switch(option)
		{
			case 0: 
				break;
			case 1: 
				t = createParseTree(t, s, G); break;
			case 2:
				printf("Traversal in level order not implemented !\n"); break;
			case 3:
				if(t != NULL){
					printParseTree(t); break;}
				else
					{printf("Create tree first (option = 1)\n"); break;}
			case 4:
				printf("type expression table not implemented fully !\n"); break;
			default :
				printf("Not an option!\n");
		}	
	}
	return 0;
}
