#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBSTHelper(const vector<int>& arr, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = sortedArrayToBSTHelper(arr, left, mid - 1);
    root->right = sortedArrayToBSTHelper(arr, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(const vector<int>& arr) {
    return sortedArrayToBSTHelper(arr, 0, arr.size() - 1);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    TreeNode* root = sortedArrayToBST(arr);

    inorder(root);
    cout << endl;
}
