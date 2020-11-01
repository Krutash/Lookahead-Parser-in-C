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

char lexemesTok[31][20] =
{
    "program", "(", ")", "{", ";", "}", "declare", ":", "list", "of", "variables", "integer", "real", "boolean",
    "array", "[", "..", "]", "jagged", "size", "values", "R1", "R2", "R3", "=", "+", "-", "*",
    "/", "&&&", "|||"
};

char terminals[33][20] =
{"PROGRAM", "ROOP", "ROCL", "BROP", "SEMICOLON", "BRCL", "DECLARE", "COLON", "LIST", "OF", "VARIABLES", "INTEGER", "REAL", "BOOLEAN",
    "ARRAY", "SQOP", "DOT", "SQCL", "JAGGED", "SIZE", "VALUES", "RONE", "RTWO", "RTHREE", "EQUAL", "PLUS", "MINUS", "MUL",
    "DIV", "AND", "OOR", "STRINGCONST", "NUM"
};
char * getToken(char *lexeme)
{
	for(int i =0; i< 31; i++)
	{
		if(strcmp(lexemesTok[i], lexeme) == 0)
		{
			return terminals[i];
		}
		else
		{
			continue;
		}
	}
	
	int len = strlen(lexeme);
	int termi = 0;
	if((lexeme[0]>=65 && lexeme[0] <=90) || (lexeme[0] >= 97 && lexeme[0] <= 122))
	{
		termi = 1;
	}
	else
	{
		for(int j = 0; j< len;j++)
		{
			if(lexeme[j] >= 48 && lexeme[j] <= 57 ) continue;
			else
			{
				return "INVALID";
			}
		}
		return terminals[32];
	}
		if(termi == 1)
	{
		for(int j = 0; j< len; j++)
		{
			if( (lexeme[j] >= 65 && lexeme[j]<= 90 )|| (lexeme[j] >= 97 && lexeme[j] <= 122)
			|| (lexeme[j] >= 48 && lexeme[j] <= 57) || (lexeme[j] == 95))
			continue;
			else{
				termi =0; break;
			}
		}
		if(termi == 1) return terminals[31];
		else return "INVALID";
	}
}

char * stripTab(char *t)
{
	char *striped = (char *)malloc(sizeof(char)*20);
	int f = 0;
	for(int i =0; i< 20;i++)
	{
		if(t[i] == '\t' || t[i] == ' '|| t[i] == '\r' || t[i] == '\n')
		{
			//printf("inhere\n");
			continue;
		}
		else
		{
			striped[f] =t[i];
			f++;
		}
	}
	//striped[f+1] = '\0';
	return striped;
}
tokenStream * tokeniseSourcecode( char *f, tokenStream *s)
{
	FILE *fp = fopen(f, "r");
	
	if(fp == NULL)
	{
		printf("Unable to open file");
		exit(1);
	}
	tokenStream *ptr = s;
	if(s == NULL)
	{
		tokenStream *head = (tokenStream *)malloc(sizeof(tokenStream));
		s = head;
		ptr = s;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		tokenStream *node = (tokenStream *)malloc(sizeof(tokenStream));
		ptr->next = node;
		ptr = ptr->next;
	}
	
	int i = 1;
	tokenStream *prev = ptr;
	tokenStream *secondlast = ptr;
	//printf("hel\n");
	while(!feof(fp))
	{
		if(feof(fp)) break;
		char c[500];
		fscanf(fp, "%[^\n]", c);
		//printf("%s\n", c);
    	char *token;
		token = strtok(c, " ");
		while(token != NULL)
		{
			int len = strlen(token);
			if(len >20)
			{
				printf("Error in tokenizing at line %d in token : %s : TOO LARGE\n", i, token);
			}
			if(len == 0)
			{
				token = strtok(NULL, " ");
				continue;
			}
			token = stripTab(token);
			char *tok = getToken(token);
			if(strcmp(tok, "INVALID") == 0)
			{
				printf("Error at line %d : %s : %s : Delimiter needed\n", i, token, tok);
				exit(1);
			}
			ptr->linenumber = i;
			strcpy(ptr->token, tok);
			strcpy(ptr->lexeme, token);
			tokenStream *node = (tokenStream *) malloc(sizeof(tokenStream));
			ptr->next = node;
			prev = ptr;
			ptr = ptr->next;
			token = strtok(NULL, " ");
		}
		i++;
		char t = fgetc(fp);
		if(t == EOF) break;
		if(feof(fp))break;
	}
	free(prev->next);
	prev->next = NULL;
	tokenStream *h = s;
	while(h->next->next != NULL)
	{
		h = h->next;
	}
	free(h->next);
	h->next = NULL;
	
	return s;
}
