#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    std::cout << std::boolalpha << hasCycle(n1) << std::endl;

    delete n1;
    delete n2;
    delete n3;

    return 0;
}
