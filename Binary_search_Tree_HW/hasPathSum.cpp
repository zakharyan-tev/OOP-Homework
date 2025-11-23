#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }

    if (!root->left && !root->right) {
        return targetSum == root->val;
    }

    int remainingSum = targetSum - root->val;
    return (hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum));
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    bool hasPath = hasPathSum(root, 27);
    cout << (hasPath ? "true" : "false") << endl;
}
