#include <iostream>
#include <vector>
#include <unordered_map>

int firstUniqChar(std::string line) {
 std::unordered_map<int, int> mp;
 for(char x : line) {

  ++mp[x];
 }

  for(int i =0 ; i < line.size() ; i++) {
   if(mp[line[i]] == 1) {
   return i;
  }
 }
 return -1;
}

int main() {
 std::cout << firstUniqChar("loveleetcode");
}
