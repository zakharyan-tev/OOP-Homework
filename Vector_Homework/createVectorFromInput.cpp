#include <iostream>
#include <vector>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec;
    int num;

    while (true) {
        std::cin >> num;
        if (num == 0) break;
        vec.push_back(num);
    }

    return vec;
}

int main() {
   std::vector<int> inputVec = createVectorFromInput();
   for(int i = 0; i <  inputVec.size(); i++) {
       std::cout <<  inputVec[i];
   }
}
