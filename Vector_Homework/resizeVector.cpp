#include <iostream>
#include <vector>

template<typename T>
void printVector(const std::vector<T>& v) {
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void resizeVector(std::vector<T>& v, size_t newSize, const T& defaultValue) {
    std::cout << "before: ";
    printVector(v);

    v.resize(newSize, defaultValue);

    std::cout << "after: ";
    printVector(v);
}

int main() {
    std::vector<int> v = {1, 2, 3};
    resizeVector(v, 5, 42);
    return 0;
}
