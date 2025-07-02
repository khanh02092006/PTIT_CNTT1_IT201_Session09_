#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct  node *next;
} node;
node *createnode(int value)
{
    node*newnode=(node*) malloc(sizeof(node));
    if (newnode==NULL)
    {
        printf(" chua cap phat");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;

}
void print_lit(node * head)
{
    node*current=head;
    while (current !=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
}
void danhsachnode(node *head)
{
    node*current=head;
    int check=1;
    while (current !=NULL)
    {
        printf("node%d:%d",check,current->data);
        current=current->next;
        check++;
    }
}
int main(void)
{
node*head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);
    print_lit(head);
    danhsachnode(head);
    return 0;
}