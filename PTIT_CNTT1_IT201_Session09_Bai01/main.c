#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct  node*next;
} node;
node * createnode(int value)
{
    node* newnode = (node*) malloc(sizeof(node));
        if (newnode ==NULL )
        {
            printf("chua duoc cap phat");
            return NULL;
        }
        newnode->data=value;
        newnode->next=NULL;
        return newnode;
}
void print_lit(node* head)
{
    node * current =head;
    while (current !=NULL)
    {
        printf("%d->",current->data);
        current =current->next;
    }
    printf("NULL\n");
}
int main(void) {
node* head= createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    head->next->next->next=createnode(40);
    head->next->next->next->next=createnode(50);
print_lit(head);
    return 0;
}
