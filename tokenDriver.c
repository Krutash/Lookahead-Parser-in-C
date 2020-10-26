#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "token.h"

int main()
{
	tokenStream *s =NULL;
	s = tokeniseSourcecode("t6.txt", s);
	printf("okay\n");
	tokenStream *ptr = s;
	while(ptr != NULL)
	{
		printf("%s %s %d\n", ptr->token, ptr->lexeme, ptr->linenumber);
		ptr = ptr->next;
	}
}
