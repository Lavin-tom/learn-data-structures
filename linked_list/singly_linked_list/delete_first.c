//singly linked list
//add first
//delete first
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int roll;
    char name[10];
    struct Node *link;           //self referencial pointer
};
struct Node * addFirst(struct Node *);
struct Node *deleteFirst(struct Node *);
void display(struct Node *);
int main()
{
    int status = 1,option;
    struct Node *head = NULL;
    while(status)
    {
        printf("1.Add_First\n2.Display\n3.Delete First\n4.Exit\nChoose any option..\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: head = addFirst(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head = deleteFirst(head);
                    break;
            default: status  = 0;
                    break;
        }
    }
}
//add first implentation
struct Node *addFirst(struct Node *head)
{
    struct Node *newnode = NULL;
    newnode = (struct Node*)calloc(1,sizeof(struct Node));        //dma allocation
    if(newnode==NULL)
        printf("node not created\n");
    else
    {
        printf("enter roll and name\n");
        scanf("%d %s",&newnode->roll,newnode->name);

        if(head == NULL)                    //if head is null asign newnode is the first node 
            head = newnode;
        else
        {
            newnode->link = head;           //connect newnode with head
            head = newnode;
        }
    }
    return head;
}
struct Node *deleteFirst(struct Node *head)
{
    struct Node *prev = NULL;
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        if(head->link == NULL)      //only one node available
        {
            free(head);
            head = NULL;
            printf("now list is empty\n");
        }
        else
        {
            prev = head;
            head = head->link;
            free(prev);
            prev = NULL;
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
            printf("Roll no: %d Name: %s\n",head->roll,head->name);
            head = head->link;
        }
    }
}