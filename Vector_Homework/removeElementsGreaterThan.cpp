#include <iostream>
#include <vector>

int removeElementsGreaterThan(std::vector<int>& v, int n) {
    int count = 0;
    while (!v.empty() && v.back() > n) {
        v.pop_back();
        count++;
    }
    return count;
}

int main() {
    std::vector<int> v = {1, 3, 5, 7, 9};
    int removed = removeElementsGreaterThan(v, 5);

    std::cout << "Removed: " << removed << std::endl;

    return 0;
}
