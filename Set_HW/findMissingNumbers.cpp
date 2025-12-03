#include <iostream>
#include <vector>
#include <set>

std::vector<int> findMissingNumbers(const std::vector<int>& nums, int N) {
    std::set<int> present(nums.begin(), nums.end());
    std::vector<int> missing;

    for (int i = 1; i <= N; ++i) {
        if (!present.count(i)) {
            missing.push_back(i);
        }
    }

    return missing;
}


int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    auto result = findMissingNumbers(nums, 6);

    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl; 
}
