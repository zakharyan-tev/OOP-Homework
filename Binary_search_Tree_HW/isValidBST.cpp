#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) {
      return true;
    }

    if (node->val <= minVal || node->val >= maxVal) {
      return false;
    }

    return (isValidBSTHelper(node->left, minVal, node->val) && isValidBSTHelper(node->right, node->val, maxVal));
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);

    bool valid = isValidBST(root);
    cout << "valid: " << (valid ? "true" : "false") << endl;

    TreeNode* invalid = new TreeNode(5);
    invalid->left = new TreeNode(7);
    invalid->right = new TreeNode(3);

    bool notValid = isValidBST(invalid);
    cout << "notValid: " << (notValid ? "true" : "false") << endl;
}
