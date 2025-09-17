#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> findIntersection(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;

    for (int x : a) {
        if (std::find(b.begin(), b.end(), x) != b.end() &&
            std::find(result.begin(), result.end(), x) == result.end()) {
            result.push_back(x);
        }
    }

    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {3, 4, 5, 6};
    std::vector<int> inter = findIntersection(a, b);

    for (int x : inter) {
        std::cout << x << " ";
    }

    return 0;
}
