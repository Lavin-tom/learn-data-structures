//doubly linked list
//add last
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;           //self referencial pointer
    struct Node *prev;
};
struct Node * addLast(struct Node *);
void display(struct Node *);
int main()
{
    int status = 1,option;
    struct Node *head = NULL;
    while(status)
    {
        printf("1.Add_Last\n2.Display\n3.Exit\nChoose any option..\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: head = addLast(head);
                    break;
            case 2: display(head);
                    break;
            default: status  = 0;
                    break;
        }
    }
}
//add last implentation
struct Node *addLast(struct Node *head)
{
    struct Node *newnode = NULL,*temp = NULL;
    newnode = (struct Node*)calloc(1,sizeof(struct Node));        //dma allocation
    if(newnode==NULL)
        printf("node not created\n");
    else
    {
        printf("enter data\n");
        scanf("%d",&newnode->data);

        if(head == NULL)                    //if head is null asign newnode is the first node 
            head = newnode;
        else
        {
            temp = head;
           while(temp->link!=NULL)
           {
            temp = temp ->link;
           }
           temp ->link = newnode;
           newnode -> prev = temp;
        }
    }
    return head;
}
//to display nodes
void display(struct Node *head)
{
    if(head== NULL)
        printf("list is empty\n");
    else
    {
        while(head)
        {
            printf("%d ",head->data);
            head = head->link;
        }
        printf("\n");
    }
}