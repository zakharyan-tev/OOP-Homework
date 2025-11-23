#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countInRange(TreeNode* root, int low, int high) {
    if (!root) {
      return 0;
    }
  
    if (root->val < low) {
        return countInRange(root->right, low, high);
    }
    else if (root->val > high) {
        return countInRange(root->left, low, high);
    }
    else {
        return (1 + countInRange(root->left, low, high) + countInRange(root->right, low, high));
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int count = countInRange(root, 7, 15);
    cout << "Count in range [7, 15]: " << count << endl; 
}
