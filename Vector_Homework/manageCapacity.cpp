#include <iostream>
#include <vector>

void manageCapacity(std::vector<int>& v){
    std::cout << "Size1: " << v.size() << "\n";
    std::cout << "Capacity1: " << v.capacity() << "\n";
    v.reserve(v.capacity() + 500);
    for (int i = 1; i <= 500; i++){
        v.push_back(i);
    }
    std::cout << "Size2: " << v.size() << "\n";
    std::cout << "Capacity2: " << v.capacity() << "\n";
}

int main() {
    std::vector<int> v = {1, 3, 5, 7, 9};
    manageCapacity(v);
    return 0;
}
