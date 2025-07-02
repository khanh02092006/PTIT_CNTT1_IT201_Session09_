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
node *inset_head(node * head,int value)
{
    node* newnode =creatnode(value);
    if (newnode== NULL)
    {
        return head;
    }
    newnode->next=head;
    return newnode;
}
int main(void)
{
    node* head = creatnode(1);
    head->next = creatnode(2);
    head->next->next = creatnode(3);
    head->next->next->next = creatnode(4);
    head->next->next->next->next = creatnode(5);

    int new_value;
    do {
        printf("Nhập số nguyên dương muốn thêm vào đầu danh sách: ");
        scanf("%d", &new_value);
        if (new_value <= 0) {
            printf("Số không hợp lệ! Nhập lại.\n");
        }
    } while (new_value <= 0);
head=inset_head(head,new_value);
    print_lit(head);
    danhsachnode(head);



    return 0;
}