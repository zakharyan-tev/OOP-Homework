#include <iostream>
#include <forward_list>

void createAndFillList(int N) {
    std::forward_list<int> lst;
  
    for (int i = 1; i <= N; ++i) {
        lst.push_front(i);
    }

    for (int value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    createAndFillList(5);
    return 0;
}
