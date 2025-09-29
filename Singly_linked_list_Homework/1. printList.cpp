#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


int main()
{
    ListNode n1(10);
    ListNode n2(20);
    ListNode n3(30);
    n1.next = &n2;
    n2.next = &n3;

    printList(&n1);
}
