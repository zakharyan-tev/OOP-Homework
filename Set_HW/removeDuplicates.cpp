#include <iostream>
#include <vector>
#include <set>

std::vector<int> removeDuplicates(const std::vector<int>& unsorted) {
//     std::set<int> unique;
//     for (auto x : unsorted) {
//         unique.insert(x); 
//     }

//     std::vector<int> sorted;
//     for (auto x : unique) {
//         sorted.push_back(x); 
//     }

//     return sorted;
//  ИЛИ

    std::set<int> unique_set(unsorted.begin(), unsorted.end());
    std::vector<int> result(unique_set.begin(), unique_set.end());
    return result;
}

int main() {
    std::vector<int> nums = {4, 2, 5, 2, 3, 4, 1};  
    std::vector<int> result = removeDuplicates(nums);

    std::cout << "Unique sorted elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
