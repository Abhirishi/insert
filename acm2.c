#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int data;
   struct node* next;

};
void print(struct node *head)
{

struct node *ptr=head;
while(ptr)
{
    printf("%d  ",ptr->data);
    ptr=ptr->next;

}
printf("\n");
}

struct node* insertfront(struct node *head)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node*));
    scanf("%d",&newnode->data);
    newnode->next=head;
    return newnode;
};

struct node* insertlast(struct node *head)
{
    struct node *newnode,*ptr=head;
   newnode=(struct node*)malloc(sizeof(struct node*));
   scanf("%d",&newnode->data);
    while(ptr->next)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    return head;
};
struct node *insertmiddle(struct node *head)
{
    struct node *ptr1,*pre1,*ptr2,*newnode;
    pre1=head;
    ptr2=pre1;
    while(ptr2->next)
    {
        ptr2=ptr2->next;
        if(ptr2->next)
        {
            ptr2=ptr2->next;
            pre1=pre1->next;
        }
    }
    ptr1=pre1->next;
   newnode=(struct node*)malloc(sizeof(struct node*));
   scanf("%d",&newnode->data);
   pre1->next=newnode;
   newnode->next=ptr1;
   return head;
};

int main()
{
    struct node *head,*ptr1,*ptr2;
    int n=9,d;

    head=(struct node*)malloc(sizeof(struct node*));
    scanf("%d",&d);
      head->data=d;
          ptr1=head;
    while(n--)

    {
       scanf("%d",&d);
        ptr2=(struct node*)malloc(sizeof(struct node*));
       ptr1->next=ptr2;
       ptr2->next=NULL;
       ptr2->data=d;
       ptr1=ptr2;
    }
    print(head);
    head=insertfront(head);
    print(head);
    head=insertlast(head);
    print(head);
    head=insertmiddle(head);
    print(head);
}
