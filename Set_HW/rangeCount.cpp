#include <iostream>
#include <set>
using namespace std;

int rangeCount(const set<int>& s, int low, int high) {
    int count = 0;
    for (auto it = s.lower_bound(low); it != s.end() && *it <= high; ++it) {
        count++;
    }
    return count;
}

int main() {
    set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << rangeCount(s, 5, 11) << '\n';
}
