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
	int key;
	struct parseTree *child;
	struct parseTree *sib;
}parseTree;

void push(char *sym, int term, int key, int line)
{
	stack st;
	strcpy(st.sym, sym); st.term = term; st.key = key;
	st.line = line;
	Stack[top] = st;
	top++;
}

stack pop()
{
	top--;
	return Stack[top];
}
stack top()
{
	return Stack[top-1];
}

parseTree *createParseTree(parseTree *t, tokenStream *s, grammar G)
{
	stack st = top();
	int i= 0;
	if(st.term == 0)
	{
		while(strcmp(st.sym, G[i].symbol) != 0)
		{
			i++;
		}
		node *nextGram = G[i].next;
		tokenStream *nextToken = s;
		parseTree *nextChild = t;
		if(strcmp(s->token, nextGram->symbol) == 0)
		{
			int flag = 0;
			
			while((strcmp(nextToken->token, nextGram->symbol) == 0)
			 && (nextToken != NULL && nextGram != NULL))
			{
				if(strcmp(nextToken->token, nextGram->symbol) == 0)
				{	parseTree *child = (parseTree *)malloc(sizeof(parseTree));
					parseTree *child2 = (parseTree *)malloc(sizeof(parseTree));	
					strcpy(child->sym, nextToken->token);
					child->line = nextToken->linenumber;
					child->term = 1;
					child->key = 1;
					strcpy(child2->sym, nextToken->lexeme);
					child2->line = nextToken->linenumber;
					child2->term = 1;
					child2->key = 0;
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
				else
				{
					char temp[20];
					strcmp(temp, nextGram->symbol);
					if(temp[0] == '<')
					{
						push(nextGram->symbol, 0, 0, nextToken->linenumber);
						parseTree *child = (parseTree *)malloc(sizeof(parseTree));
						
						strcpy(child->sym, nextGram->symbol);
						child->term = 0;
						child->child = NULL;
						child->sib = NULL;
						if(flag)
						{
							nextChild->sib = child;
							nextChild = nextChild->sib;
						}
						else
						{
							nextChild->child = child;
							nextChild = nextChild->child;
							flag++;
						}
						nextChild = createParseTree(nextChild, nextToken, G);
					}
				}
			}
			pop();
		}
		
		else
		{
			tokenStream *temp =s;
			if(nextGram->next !== NULL)
			{
				if(strcmp(temp->next, nextGram->next->symbol) == 0)
				{
					push(nextGram->symbol, 0, 0, nextToken->linenumber);
					parseTree *child = (parseTree *)malloc(sizeof(parseTree));
					strcpy(child->sym, nextGram->symbol);
					child->term = 0;
					child->child = NULL;
					child->sib = NULL;
					nextToken
					
				}
			}
			if(strcmp(temp->next, nextGram->next->symbol))
		}
		
		
	}
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
