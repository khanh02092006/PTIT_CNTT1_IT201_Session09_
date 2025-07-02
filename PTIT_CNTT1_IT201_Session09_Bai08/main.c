#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
struct node {
    int data;
    struct node* next;
};
typedef struct node node;

// Hàm tạo node mới
node* create_node(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Hàm chèn node vào đầu danh sách
node* insert_at_head(node* head, int value) {
    node* newnode = create_node(value);
    if (newnode == NULL) return head;
    newnode->next = head;
    return newnode;
}

// Hàm xóa node tại vị trí position
node* delete_at_position(node* head, int position) {
    if (head == NULL) {
        printf("Danh sách rỗng, không có gì để xóa!\n");
        return NULL;
    }
    if (position <= 0) {
        printf("Vị trí không hợp lệ!\n");
        return head;
    }

    // Xóa node đầu (position == 1)
    if (position == 1) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Tìm node trước vị trí cần xóa
    node* current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    // Kiểm tra nếu vị trí vượt quá chiều dài danh sách
    if (current == NULL || current->next == NULL) {
        printf("Vị trí vượt quá chiều dài danh sách! Không xóa được.\n");
        return head;
    }

    // Xóa node tại vị trí position
    node* temp = current->next; // Node cần xóa
    current->next = temp->next; // Liên kết lại danh sách
    free(temp); // Giải phóng bộ nhớ
    return head;
}

// Hàm in danh sách liên kết
void print_list(node* head) {
    node* current = head;
    if (current == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    node* head = NULL;
    int position;

    // Tạo danh sách mẫu
    head = insert_at_head(head, 7);
    head = insert_at_head(head, 5);
    head = insert_at_head(head, 3);
    printf("Danh sách ban đầu: ");
    print_list(head);

    // Yêu cầu người dùng nhập vị trí cần xóa
    printf("Nhập vị trí cần xóa: ");
    scanf("%d", &position);

    // Xóa node tại vị trí đã nhập
    head = delete_at_position(head, position);

    // In danh sách sau khi xóa
    printf("Danh sách sau khi xóa: ");
    print_list(head);

    // Giải phóng bộ nhớ danh sách
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}