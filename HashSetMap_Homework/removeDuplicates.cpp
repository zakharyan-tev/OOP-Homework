#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> removeDuplicates(const std::vector<int>& unsorted) {


    std::unordered_set<int> unique_set(unsorted.begin(), unsorted.end());
    std::vector<int> result(unique_set.begin(), unique_set.end());
    return result;
}

int main() {
    std::vector<int> nums = {4, 2, 5, 2, 3, 4, 1};  
    std::vector<int> result = removeDuplicates(nums);

    std::cout << "Unique unordered elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
