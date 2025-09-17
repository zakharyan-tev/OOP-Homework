#include <iostream>
#include <vector>
#include <algorithm>

class VectorStats {
private:
    std::vector<double> data;

public:
    VectorStats(const std::vector<double>& vec) : data(vec) {}

    double mean() const {
        if (data.empty()) return 0.0;
        double sum = 0;
        for (double x : data) sum += x;
        return sum / data.size();
    }

    double median() {
        if (data.empty()) return 0.0;
        std::vector<double> temp = data;
        std::sort(temp.begin(), temp.end());
        size_t n = temp.size();
        if (n % 2 == 1) return temp[n / 2];
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    }

    void addValue(double value) {
        data.push_back(value);
    }

    void removeValue(double value) {
        auto it = std::find(data.begin(), data.end(), value);
        if (it != data.end()) data.erase(it);
    }
};

int main() {
    VectorStats stats({1.0, 2.0, 3.0, 4.0});
    std::cout << "Mean: " << stats.mean() << "\n";      // 2.5
    std::cout << "Median: " << stats.median() << "\n";  // 2.5

    stats.addValue(5.0);
    stats.removeValue(2.0);

    std::cout << "Mean after update: " << stats.mean() << "\n";
    std::cout << "Median after update: " << stats.median() << "\n";
}
