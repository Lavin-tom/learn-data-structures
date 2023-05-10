//dispaly -for debug

#include"myheader.h"
void display (struct stack *ptr)
{
	struct stack *temp=NULL;
	if(ptr==NULL)
	{
		printf("\nstack is empty\n");
	}
	else
	{
		printf("\nstack\n");
		temp=ptr;
		while(temp)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}
