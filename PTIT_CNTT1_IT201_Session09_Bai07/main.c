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
node *insert_pos(node *head, int value,int pos)
{
    if (pos<0)
    {
        printf(" vi tri kong hop le");
        return head;

    }
    node*newnode=creatnode(value);
    if (newnode==NULL)
    {
        return head;
    }
    if (pos==1)
    {
        newnode->next=head;
        return newnode;
    }
    node *current=head;
    int count=1;
    while (current!=NULL && count<pos -1)
    {
        current=current->next;
        count++;
    }
    if (current== NULL)
    {
        printf(" vuot qua danh sach");
        free(newnode);
        return head;
    }
    newnode->next=current->next;
    current->next=newnode;
     return head;
}

int main(void)
{
    node* head = creatnode(1);
    head->next = creatnode(2);
    head->next->next = creatnode(3);
    head->next->next->next = creatnode(4);
    head->next->next->next->next = creatnode(5);


    int value, pos;
    printf("Nhập giá trị muốn thêm: ");
    scanf("%d", &value);
    printf("Nhập vị trí muốn thêm (>=1): ");
    scanf("%d", &pos);

    head = insert_pos(head, value, pos);

    printf("Danh sách sau khi chèn:\n");
    print_lit(head);
    danhsachnode(head);


    return 0;
}