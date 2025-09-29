#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next){ //եթե կամ բան չկա, կամ մի հատ ա մեջը ավտոմատ ճիշտ ա գալիս
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr;

    ListNode* prev = nullptr;
    while (secondHalf) {
        ListNode* nextNode = secondHalf->next;
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = nextNode;
    }
    secondHalf = prev;

    ListNode* firstHalf = head;
    ListNode* secondHalfCopy = secondHalf;

    bool palindrome = true;
    while (firstHalf && secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    prev = nullptr;
    while (secondHalfCopy) {
        ListNode* nextNode = secondHalfCopy->next;
        secondHalfCopy->next = prev;
        prev = secondHalfCopy;
        secondHalfCopy = nextNode;
    }
    slow->next = prev;

    return palindrome;
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

void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


int main() {
    ListNode* palindromeList = createList(1, 2, 2, 1);
    std::cout << "Is palindrome? " << std::boolalpha << isPalindrome(palindromeList) << std::endl;

    ListNode* notPalindromeList = createList(1, 2, 3);
    std::cout << "Is palindrome? " << isPalindrome(notPalindromeList) << std::endl;

    while (palindromeList) {
        ListNode* tmp = palindromeList;
        palindromeList = palindromeList->next;
        delete tmp;
    }

    while (notPalindromeList) {
        ListNode* tmp = notPalindromeList;
        notPalindromeList = notPalindromeList->next;
        delete tmp;
    }

    return 0;
}






