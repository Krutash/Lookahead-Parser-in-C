#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"read.h"

grammar getPoint(grammar G)
{
	G = (grammar)malloc(sizeof(data)*50);
	return G;
}

grammar readGrammar(FILE *fp, grammar G)
{
	if(fp == NULL){
		printf("unable to open the file\n");
		exit(1);
	}
	int i =0;
	
	while(!feof(fp))
	{
		if(feof(fp)) break;
		char c[150];
		fscanf(fp, "%[^\n]", c);
		//printf("%s\n", c);
    	char *token;
		token = strtok(c, " ");
		int flag = 0;
		data *nextptr;
		while(token != NULL)
		{
			if(strcmp("->", token) == 0)
			{
				token = strtok(NULL, " ");
				continue;
			}
			if(flag == 0)
			{
				strcpy(G[i].symbol, token);
				G[i].next = NULL;
				//printf("helo %s\n", G[i].symbol);
				flag++;
			}
			else if(flag == 1)
			{
				data *temp2 = (data *)malloc(sizeof(data));
				strcpy(temp2->symbol, token);
				temp2->next = NULL;
				G[i].next = temp2;
				flag++;
				nextptr = G[i].next;
				//printf("..%s..", nextptr->symbol);
			}
			else
			{
				data *temp3 = (data *)malloc(sizeof(data));
				strcpy(temp3->symbol,token);
				temp3->next = NULL;
				nextptr->next = temp3;
				nextptr = nextptr->next;
				//printf("..%s..", nextptr->symbol);
			}
			token = strtok(NULL, " ");
		}
		printf("\n");i++;
		x =i;
		char t = fgetc(fp);
		if(t == EOF) break;
		if(feof(fp))break;
	}
	fclose(fp);
	return G;
}

	
