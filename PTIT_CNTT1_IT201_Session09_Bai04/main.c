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
int coundnode(node *head)
{
    int count=0;
    node*current=head;
    while (current!= NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
int main(void)
{
    node* head = creatnode(1);
    head->next = creatnode(2);
    head->next->next = creatnode(3);
    head->next->next->next = creatnode(4);
    head->next->next->next->next = creatnode(5);
    print_lit(head);
    danhsachnode(head);
    int let=coundnode(head);
    printf(" danh sach lien ket co %d phan tu",let);



    return 0;
}