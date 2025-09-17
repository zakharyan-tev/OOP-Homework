#include <iostream>
#include <vector>

class DynamicMatrix {
private:
    std::vector<std::vector<int>> data;

public:
    DynamicMatrix(int rows, int cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    int getElement(int row, int col) const {
        return data.at(row).at(col);
    }

    void setElement(int row, int col, int value) {
        data.at(row).at(col) = value;
    }

    void addRow() {
        if (data.empty()) {
            data.push_back(std::vector<int>(1, 0));
        } else {
            data.push_back(std::vector<int>(data[0].size(), 0));
        }
    }

    void addColumn() {
        if (data.empty()) {
            data.push_back({0});
        } else {
            for (auto& row : data) {
                row.push_back(0);
            }
        }
    }

    void print() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    DynamicMatrix matrix(3, 3);
    matrix.setElement(1, 1, 42);
    matrix.addRow();
    matrix.addColumn();
    matrix.print();
}
