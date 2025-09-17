#include <iostream>
#include <vector>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& v, Predicate pred) {
    std::vector<T> newV;
    for (const T& x : v) {
        if (pred(x)) {
            newV.push_back(x);
        }
    }
    return newV;
}

bool isEven(int x) { return x % 2 == 0; }

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> filtered = filterVector(vec, isEven);

    for (const int& x : vec) {
        std::cout << x;
    }

    std::cout << "\n";

    for (const int& x : filtered) {
        std::cout << x;
    }
}
