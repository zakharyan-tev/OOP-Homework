#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

template <typename... Args>
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
    ListNode* head = createList(1, 2, 3, 4, 5);
    std::cout << "Before reverse: ";
    printList(head);

    head = reverseList(head);

    std::cout << "After reverse: ";
    printList(head);

    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
