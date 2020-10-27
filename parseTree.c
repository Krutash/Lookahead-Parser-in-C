#include<stdio.h>
#include<stdlib.h>
#include"token.h"
#include"read.h"

typedef struct stack
{
	char sym[20];
	int term;
	int key;
	int line;
}stack;

stack Stack[100];
int top = 0;

typedef struct parseTree
{
	char sym[20];
	int line;
	int term;
	struct parseTree *child;
	struct parseTree *sib;
}parseTree;

parseTree *createParseTree(parseTree *t, tokenStream *s, grammar G)
{
	if(t == NULL)
	{
		t = (parseTree *)malloc(sizeof(parseTree));
		strcpy(t->sym, Stack[top]);
		t->term = Stack[top];
		t->line = Stack[top];
	}
	
}

parseTree* inTree(grammar G, tokenStream *s)
{
	parseTree *t = (parseTree *)malloc(sizeof(parseTree));
	strcpy(t->sym, G[0].symbol);
	t->line = 1;
	t->term = 0;
	t->sib = NULL;

	node *nextGram = G[i].next;
	
	tokenStream *nextToken = s;
	
	parseTree *nextChild = t;
	
	int flag = 0;
	
	while((strcmp(nextToken->token, nextGram->symbol) == 0) 
	&& (nextToken != NULL && nextGram != NULL))
	{
		parseTree *child = (parseTree *)malloc(sizeof(parseTree));
		parseTree *child2 = (parseTree *)malloc(sizeof(parseTree));
		
		strcpy(child->sym, nextToken->token);
		child->line = nextToken->linenumber;
		child->term = 1;
		
		strcpy(child2->sym, nextToken->lexeme);
		child2->line = nextToken->linenumber;
		child2->term = 1;
		child2->child = NULL;
		child2-sib = NULL;
		
		child->child= child2;
		
		if(flag= 0)
		{
			nextChild->child = child;
			flag++;
		}
		else
		{
			nextChild->sib = child;
			nextChild = nextChild->sib;
		}
		
		nextToken = nextToken->next;
		nextGram = nextGram->next;
	}
}

int main()
{
	
}

