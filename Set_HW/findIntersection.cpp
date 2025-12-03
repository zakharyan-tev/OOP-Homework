#include <iostream>
#include <vector>
#include <set>

std::vector<int> findIntersection(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::set<int> s1(v1.begin(), v1.end());
    std::set<int> s2(v2.begin(), v2.end());

    std::vector<int> res;
    for (int x : s1) {
        if (s2.count(x)) {
            res.push_back(x);
        }
    }
    return res;
}

int main() {
    std::vector<int> arr1 = {4, 2, 5, 2, 3, 4, 1};
    std::vector<int> arr2 = {4, 90, 55, 28, 37, 54, 1};

    std::vector<int> result = findIntersection(arr1, arr2);

    std::cout << "Intersection: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
