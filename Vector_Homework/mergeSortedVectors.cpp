#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeSortedVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<int> merged;
    merged.reserve(v1.size() + v2.size());

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(merged));
    return merged;
}

int main() {
    std::vector<int> v1 = {1, 3, 5};
    std::vector<int> v2 = {2, 4, 6};
    std::vector<int> v3 = mergeSortedVectors(v1, v2);

    for (int x : v3) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
