#include <iostream>
#include <set>
using namespace std;

int removeRange(set<int>& s, int low, int high) {
    auto itLow = s.lower_bound(low);
    auto itHigh = s.upper_bound(high);

    int count = distance(itLow, itHigh);

    s.erase(itLow, itHigh);

    return count;
}

int main() {
    set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    int removed = removeRange(s, 5, 11);
    cout << removed << '\n';
    for (int x : s) cout << x << " ";
    cout << endl;
}
