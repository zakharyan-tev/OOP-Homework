#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool search(TreeNode* root, int target) {
    if (!root) {
      return false;
    }
  
    if (root->val == target) {
      return true;
    }
  
    if (target < root->val) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    bool found = search(root, 3);
    bool notFound = search(root, 10);

    cout << "found: " << (found ? "true" : "false") << endl;
    cout << "notFound: " << (notFound ? "true" : "false") << endl;
}
