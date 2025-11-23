#include <iostream>
#include <stdexcept>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMinBST(TreeNode* root) {
    if (!root) throw runtime_error("Empty tree");
    TreeNode* current = root;
    while (current->left) {
        current = current->left;
    }
    return current->val;
}

int findMaxBST(TreeNode* root) {
    if (!root) throw runtime_error("Empty tree");
    TreeNode* current = root;
    while (current->right) {
        current = current->right;
    }
    return current->val;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);

    int minVal = findMinBST(root);
    int maxVal = findMaxBST(root);

    cout << "Min: " << minVal << ", Max: " << maxVal << endl;
}
