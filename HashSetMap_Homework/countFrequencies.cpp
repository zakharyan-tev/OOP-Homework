#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<char, int> countFrequencies(std::string st) {
 std::unordered_map<char, int> mp;

 for(const auto& c : st) {

  ++mp[c];
 }
 return mp;
}


int main() {
 std::string s = "hello world";
 auto freqs = countFrequencies(s);

 std::cout << "l: " << freqs['l'] << std::endl; // 3
 std::cout << "o: " << freqs['o'] << std::endl; // 2
 std::cout << "h: " << freqs['h'] << std::endl; // 1
}
