#include <iostream>
#include <set>
#include <vector>
using namespace std;

int findClosest(set<int>& s, int target) {
	if(s.empty()) {
		return 0;
	}

	auto it = s.lower_bound(target);

	if (it == s.begin()) {
		return *it;
	}

	else if (it == s.end()) {
		it--;
		return *it;
	}

	else {
		int cur = *it;
		it--;
		int prev = *it;
		if (abs(cur - target) >= abs(prev - target)) {
			return prev;
		}
		else return cur;
	}
}


int main() {
	std::set<int> s = {1, 5, 10, 15, 20};
	std::cout << findClosest(s, 12) << '\n';
	std::cout << findClosest(s, 13) << '\n';
}
