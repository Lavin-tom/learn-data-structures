//doubly linked list
//add first
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;           //self referencial pointer
    struct Node *prev;
};
struct Node * addFirst(struct Node *);
struct Node *reverseList(struct Node *head);
void display(struct Node *);
int main()
{
    int status = 1,option;
    struct Node *head = NULL;
    while(status)
    {
        printf("1.Add_First\n2.Display\n3.Revese\n4.Exit\nChoose any option..\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: head = addFirst(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head = reverseList(head);
                    break;
            default: status  = 0;
                    break;
        }
    }
}
//add last implentation
struct Node *addFirst(struct Node *head)
{
    struct Node *newnode = NULL;
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
            newnode->link = head;           //connect newnode with head
            head->prev = newnode;
            head = newnode;
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
//reverse list
struct Node *reverseList(struct Node *head)
{
    struct Node *current = NULL,*temp = NULL;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        if(head->link == NULL)                    //if head is null asign newnode is the first node 
            printf("Only one node is available, reverse is not required\n");
        else
        {
            current = head;
            while(current!=NULL)
            {
                temp = current->prev;                       //swapping logic with temp variable
                current -> prev = current ->link;
                current->link = temp;

                current = current->prev;
            }
        }
        head = temp->prev;
    }
    return head;
}