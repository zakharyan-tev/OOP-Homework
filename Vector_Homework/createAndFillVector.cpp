#include <iostream>
#include <vector>

void createAndFillVector(int N) {
    std::vector<int> vec(N);

    for (int i = 0; i < N; ++i) {
        vec[i] = i + 1;
    }

    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
}

int main() {
    std::vector<int> vec(5);
    createAndFillVector(5);

    return 0;
}
