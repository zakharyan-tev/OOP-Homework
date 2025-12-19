#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
 std::unordered_set<int> set1(nums1.begin(), nums1.end());
 std::unordered_set<int> resultSet;

 for (int num : nums2) {
  if (set1.count(num)) {
   resultSet.insert(num);
  }
 }

 return std::vector<int>(resultSet.begin(), resultSet.end());
}

int main() {
 std::vector<int> nums1 = {1, 2, 2, 1};
 std::vector<int> nums2 = {2, 2};

 auto res = intersection(nums1, nums2);

 for (int x : res) {
  std::cout << x << " ";
 }
 return 0;
}
