#include <iostream>
#include <vector>

std::vector<std::vector<int>> groupAdjacent(std::vector<int>& v) {
    std::vector<std::vector<int>> res;

    if (v.empty()) {
        return res;
    }

    res.push_back({v[0]});
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i-1]) {
            res.back().push_back(v[i]);
        } else {
            res.push_back({v[i]});
        }
    }
    return res;
}

int main()
{
    std::vector<int> v = {1, 1, 2, 2, 2, 3, 1, 1};
    std::vector<std::vector<int>> res = groupAdjacent(v);

    for (int i = 0; i < res.size(); ++i) {
        for (int el : res[i]) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

