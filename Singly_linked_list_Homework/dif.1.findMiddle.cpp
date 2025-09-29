#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* findMiddle(ListNode* head) {
    if (!head) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template <typename... Args>
ListNode* createList(int first) {
    return new ListNode(first);
}

template <typename... Args>
ListNode* createList(int first, Args... args) {
    ListNode* head = new ListNode(first);
    head->next = createList(args...);
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
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    ListNode* list1 = createList(1, 2, 3, 4, 5);
    ListNode* middle1 = findMiddle(list1);
    std::cout << "Middle of list1: " << middle1->data << std::endl;

    ListNode* list2 = createList(1, 2, 3, 4, 5, 6);
    ListNode* middle2 = findMiddle(list2);
    std::cout << "Middle of list2: " << middle2->data << std::endl;

    deleteList(list1);
    deleteList(list2);

    return 0;
}
