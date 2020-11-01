/* 
Group 28
Utkarsh Kumar 2017B2A71008P
Suchisattam Saran 2017B2A70585P
Supratik Bhattacharya 2017B2A70745P
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"def.h"

typedef struct stack
{
	char sym[20];
	int line;
}stack;

typedef struct stack stack;

stack Stack[200];
int TOP = 0;
parseTree *treenext;
void push(char *sym, int line)
{
	stack st;
	strcpy(st.sym, sym);
	st.line = line;
	fflush(stdout);
	Stack[TOP] = st;
	TOP++;
}

void pop()
{
	if(TOP == 0)return;
	TOP--;
	strcpy(Stack[TOP].sym, "");
	fflush(stdout);
	return;
}
stack top()
{
	if(TOP >0)
	return Stack[TOP-1];
	
	else
		return Stack[0];
}
int moves = 0;
parseTree *createParse(parseTree *t, tokenStream *s, grammar G)
{
	fflush(stdout);
	if(TOP == 0) return t;
	stack st = top();
	int i = st.line+1;
	int epse = 0;
	
	node *nextGram = G[st.line].next;
	tokenStream *nextToken = s;
	parseTree *nextChild = t;
	int flag = 0;
	int mov = 0;
	while(nextToken != NULL && nextGram != NULL)
	{	
		parseTree *child = (parseTree *)malloc(sizeof(parseTree));
		parseTree *child2 = (parseTree *)malloc(sizeof(parseTree));
		//printf("%s...%s.\n",nextToken->token,  nextGram->symbol);
		fflush(stdout);
		int mat = 1;
		for(int p = 0; p<3; p++)
		{
			if(nextToken->token[p] != nextGram->symbol[p])
			{	mat = 0;
				break;
			}
			else mat = 1;
		}
		if(strcmp(nextToken->token, nextGram->symbol)==0 || mat == 1)
		{
			mov++;
			strcpy(child->sym, nextToken->token);
			//printf("token : %s\n", nextToken->token);
			child->line = nextToken->linenumber;
			child->term = 1;
			child->key = 1;
			child->child = NULL;
			strcpy(child2->sym, nextToken->lexeme);
			child2->line = nextToken->linenumber;
			child2->term = 1;
			child2->key = 0;
			child2->child = NULL;
			child->child = child2;
			if(flag)
			{
				treenext->child = child;
				treenext = treenext->child;
			}
			else
			{
				treenext->child = child;
				treenext = treenext->child;
				flag++;
			}
			nextToken = nextToken->next;
			nextGram = nextGram->next;
			if(nextToken == NULL)printf("yes praseTree formed\n");
			
		}
		else
		{
			//if(flag != 0)//printf("grammar symb ...%d.. %s\n",nextToken->linenumber, nextGram->symbol);
			parseTree *CHILD = (parseTree *)malloc(sizeof(parseTree));
			int found = 1+st.line;
			int eps =0;
			if(found == 4 || found == 8 || found == 15 || found == 21 || found == 25
				|| found == 27 || found == 29 || found == 31 || found == 41)eps = 1;
			fflush(stdout);
			if(eps == 1)
			{
				//printf("eps for : %s\n",st.sym);
				strcpy(CHILD->sym, "EPS");
				CHILD->child = NULL;
				CHILD->term = 1;
				CHILD->key = 1;
				CHILD->line = nextToken->linenumber;
				treenext->child = CHILD;
				treenext = treenext->child;
				pop();
				return t;
			}
			else
			{
				found = 0;
			}
			int look = 0;
			int yes = 0;
			while(look < 43)
			{
				int match = 0;
				
				for(int p = 0; p<20; p++)
				{
					if(nextGram->symbol[p] != G[look].symbol[p]) break;
					else if(p == 15 || (nextGram->symbol[p] == 62 
					&& G[look].symbol[p] == 62))
					{
						match = 1;break;
					}
				}
				if(match == 1)
				{
					found = look;
					int eq = 1;
					while(strcmp(G[look].symbol, G[found].symbol)==0)
					{	
						for(int p= 0; p<3; p++)
						{
							if(nextToken->token[p] != G[found].next->symbol[p])
								{eq = 0; break;}
							else continue;
						}
						
						if(strcmp(nextToken->token, G[found].next->symbol)== 0 
						|| strcmp(G[found].next->symbol, "EPS") == 0
						|| eq == 1)
						{
							yes = 1;//printf("Match !\n");
						}
						if(yes)break;
						else
						found++;
					}
					int epsy = 0;
					if(yes == 0)
					{	
						if(found == 4 || found == 8 || found == 15 || found == 21 || found == 25
						|| found == 27 || found == 29 || found == 31 || found == 41)
						{
							found--;
							yes = 1;
							epsy = 1;
						}
					}
					if(yes == 1)
					{
						strcpy(CHILD->sym, G[found].symbol);
						CHILD->child = NULL;
						CHILD->term = 0; CHILD->key = 0;
						CHILD->gram = found;
						CHILD->line = nextToken->linenumber;
						if(flag){
							treenext->child = CHILD;
							treenext = treenext->child;
						}
						else{
							treenext->child = CHILD;
							treenext = treenext->child;
							flag++;
						}
						push(G[found].symbol, found);
						//printf("pushed...%s\n", G[found].symbol);
						createParse(nextChild, nextToken, G);
						int mo = moves;
						while(mo >0 && epsy == 0)
						{
							mov++;
							nextToken = nextToken->next;
							mo--;
							if(nextToken == NULL)break;
						}
					}
				}
				if(yes) break;
				look++;
			}
			if(look >= 42)
			{
				printf("Error: wrong token please check file format at line : %d for token :%s\n", nextToken->linenumber, nextToken->token);exit(1);
			}
			nextGram = nextGram->next;
		}
	}
	pop();
	//if(nextToken == NULL)printf("parse Tree created sucessfully\n");
	moves = mov;
	return t;
}

parseTree *createParseTree(parseTree *t, tokenStream *s, grammar G)
{
	t = (parseTree *)malloc(sizeof(parseTree));
	
	push(G[0].symbol, 0);
	strcpy(t->sym, G[0].symbol);
	t->term = 0;
	t->key = 0;
	t->child = NULL;
	t->gram;
	t->line = 1;
	treenext = t;
	createParse(t, s, G);
	return t;
}
