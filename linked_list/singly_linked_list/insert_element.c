//singly linked list

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;           //self referencial pointer
};
struct Node * addLast(struct Node *);
struct Node * insertNode(struct Node *,int,int);
void display(struct Node *);
int main()
{
    int status = 1,option,position,data;
    struct Node *head = NULL;
    while(status)
    {
        printf("1.Insert\n2.Display\n3.Exit\nChoose any option..\n");
        scanf("%d",&option);
        switch(option)
        {
            case 2: display(head);
                    break;
            case 1: 
                    printf("enter data and index\n");
                    scanf("%d %d",&data,&position);
                    head = insertNode(head,data,position);
                    break;
            default: status  = 0;
                    break;
        }
    }
}
struct Node *insertNode(struct Node *head, int data, int position)
{
    struct Node *newnode = NULL, *temp = NULL, *prev = NULL;
    newnode = (struct Node*)calloc(1,sizeof(struct Node));    //dma allocation
    if(newnode==NULL)
        printf("node not created\n");
    else
    {
        newnode->data = data;

        if(head == NULL)                  //if head is null, assign newnode as the first node 
            head = newnode;
        else if(position == 1)             //if position is 1, insert the new node at the beginning
        {
            newnode->link = head;
            head = newnode;
        }
        else
        {
            //traverse to the node before the position to insert the new node
            temp = head;
            for(int i = 1; i < position && temp != NULL; i++)
            {
                prev = temp;
                temp = temp->link;
            }

            if(temp == NULL)              //if position is greater than the number of nodes in the list
            {
                printf("Invalid position\n");
                free(newnode);
            }
            else
            {
                //insert the new node between prev and temp
                prev->link = newnode;
                newnode->link = temp;
            }
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
