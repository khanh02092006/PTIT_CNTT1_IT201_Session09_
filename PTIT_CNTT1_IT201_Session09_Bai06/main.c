#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct node *next;
} node ;
node *creatnode(int value)
{

   node* newnode = (node*)malloc(sizeof(node));
       newnode->data= value;
       newnode ->next=NULL;
       return newnode;
}
void print_lit(node * head)
{
    node * current=head;
    while (current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
void danhsachnode(node* head)
{
    node* current=head;
    int cound=1;
    while (current!=NULL)
    {
        printf("node%d:%d->",cound,current->data);
        current=current->next;
        cound++;
    }
}
node *delete_head(node * head)
{
    if (head== NULL)
    {
        printf(" khong co phan tu nao de xoa");
        return NULL;
    }
    node* tmep= head;
    head=head->next;
    free(tmep);
    return head;
}

int main(void)
{
    node* head = creatnode(1);
    head->next = creatnode(2);
    head->next->next = creatnode(3);
    head->next->next->next = creatnode(4);
    head->next->next->next->next = creatnode(5);
    print_lit(head);
head=delete_head(head);
    print_lit(head);




    return 0;
}