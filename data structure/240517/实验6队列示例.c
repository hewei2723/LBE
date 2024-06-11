#include "stdio.h"

#define MAXN  26

char q[MAXN];
int head = -1, tail = -1;

int en_queue(x)
	char x;
	{if (tail == MAXN-1)
		return(1);
	q[++tail] = x;
	return(0);
}

int de_queue(p_y)
	char *p_y;
	{if (head == tail)
		return(1);
	*p_y = q[++head];
	return(0);
}

main()
{   int i;
	char ch_x,ch_y;

	printf("input the char you want to enqueue\n");
	scanf("%c",&ch_x);
	while(ch_x!='0')
		if (en_queue(ch_x)==1)  printf("failure!\n");
		else
			{printf("success!\n");
			printf("input a char for ch_x to enqueue\nch_x=");
			getchar();
			scanf("%c",&ch_x);}
	i=1;
	while(q[i]!='\0')
		{printf("%c ", q[i]);
		i++;}

	if (de_queue(&ch_y)==1)  printf("failure!\n");
	else
		{printf("success!\n");
		printf("The dequeue char is %c\n",ch_y);}
	for (i=head+1; i<=tail; i++)
		printf("%c ", q[i]);
}