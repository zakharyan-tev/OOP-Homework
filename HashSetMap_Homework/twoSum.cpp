#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

// std::vector<int> twoSum(const std::vector<int>& nums, int target) {
//  std::unordered_map<int, int> seen;

//  for (int i = 0; i < nums.size(); ++i) {
//   int need = target - nums[i];

//   if (seen.count(need)) {
//    return {seen[need], i};
//   }


//   seen[nums[i]] = i;
//  }


//  return {};
// }

std::pair<int, int> twoSum(const std::vector<int>& nums, int target) {
 std::unordered_map<int, int> seen;

 for (int i = 0; i < nums.size(); ++i) {
  int complement = target - nums[i];

  if (seen.count(complement)) {
   return {seen[complement], i};
  }

  seen[nums[i]] = i;
 }

 return {-1, -1};
}


int main() {

 std::vector<int> nums = {2, 7, 11, 15};
 int target = 9;
 auto result = twoSum(nums, target);
//  if(!res.empty()) {
//   std::cout << "{" << result[0] << "," << result[1] << "}"<<std::endl;
//  }
 std::cout << "{" << result.first << "," << result.second << "}" << std::endl;

}
