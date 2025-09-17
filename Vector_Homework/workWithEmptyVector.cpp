#include <iostream>
#include <vector>

void workWithEmptyVector() {

    std::vector<int> v;
    std::cout << "size = " << v.size();
    std::cout << "cap = 0 " << v.capacity();
    for(int i =0 ; i< 10; i++) {
        v.psuh_back(i+1);
    }
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    workWithEmptyVector();
    return 0;
}
