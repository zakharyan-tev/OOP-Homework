#include <iostream>
#include <vector>

bool isValidPopSequence(const std::vector<int>& removed) {
    for (size_t i = 1; i < removed.size(); ++i) {
        if (removed[i] >= removed[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> removed = {100, 50, 40, 10};
    bool ok = isValidPopSequence(removed);

    std::cout << (ok ? "true" : "false") << "\n"; 
}
