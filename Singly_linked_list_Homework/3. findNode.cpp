#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

bool findNode(ListNode* head, int value) {

    while (head) {
        if (head->data == value) {
            return true;
        }
        return false;

    }
}


int main()
{
    ListNode n1(10);
    ListNode n2(20);
    ListNode n3(30);
    n1.next = &n2;
    n2.next = &n3;

    std::cout << findNode(&n1, 10);
}
