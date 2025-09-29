#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* deleteValue(ListNode* head, int value) {
    while (head && head->data == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr) return nullptr;

    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp; 
        } else {
            current = current->next;
        }
    }

    return head;
}

void printcount(ListNode* head) {
    size_t count = 0;
    while (head) {
        std::cout << head->data << " ";
        count++;
        head = head->next;
    }
    std::cout << std::endl;
    std::cout << count << std::endl;
}

int main() {
    
    ListNode* n1 = new ListNode(10);
    ListNode* n2 = new ListNode(20);
    ListNode* n3 = new ListNode(30);
    ListNode* n4 = new ListNode(20);
    ListNode* n5 = new ListNode(40);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* newHead = deleteValue(n1, 20);

    printcount(newHead);

    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
