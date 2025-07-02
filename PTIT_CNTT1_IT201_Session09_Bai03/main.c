#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Không cấp phát được bộ nhớ!\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void search_node(node* head, int value) {
    node* current = head;
    int found = 0;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) {
            printf("Tìm thấy giá trị %d tại Node %d\n", value, position);
            found = 1;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        printf("Không tìm thấy phần tử %d trong danh sách.\n", value);
    }
}

void danhsach_node(node* head) {
    node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Node %d: %d\n", count, current->data);
        current = current->next;
        count++;
    }
}

int main(void) {
    node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    print_list(head);
    danhsach_node(head);

    int n;
    do {
        printf("Nhập phần tử muốn tìm: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Không hợp lệ! Nhập lại.\n");
        }
    } while (n <= 0);

    search_node(head, n);

    return 0;
}
