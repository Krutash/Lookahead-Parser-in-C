#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "token.h"

int main()
{
	tokenStream *s =NULL;
	s = tokeniseSourcecode("testcase.txt", s);
	//printf("okay\n");
	tokenStream *ptr = s;
	int flag = 0;
	while(ptr != NULL && flag <=10)
	{
		printf("%s %s %d\n", ptr->token, ptr->lexeme, ptr->linenumber);
		ptr = ptr->next;
		flag ++;
	}
}
