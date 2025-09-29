#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

void removeDuplicates(ListNode* head) {
    ListNode* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
            ListNode* tmp = current->next;
            current->next = tmp->next;
            delete tmp;
        } else {
            current = current->next;
        }
    }
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* createList(int val) {
    return new ListNode(val);
}

template <typename... Args>
ListNode* createList(int first, Args... args) {
    ListNode* head = new ListNode(first);
    head->next = createList(args...);
    return head;
}

int main() {
    ListNode* head = createList(1, 1, 2, 3, 3);
    std::cout << "Before removing duplicates: ";
    printList(head);

    removeDuplicates(head);

    std::cout << "After removing duplicates: ";
    printList(head);

    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
