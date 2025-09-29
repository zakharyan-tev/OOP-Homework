#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

template <typename... Args>
ListNode* createList(Args&&... args) {
    ListNode* head = nullptr;
    ListNode** curr = &head;

    ((*curr = new ListNode(args), curr = &((*curr)->next)), ...);

    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* head = createList(1, 0, 1, 1);

    std::cout << "Created list: ";
    printList(head);

    deleteList(head);

    return 0;
}
