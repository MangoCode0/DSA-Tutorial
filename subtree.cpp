#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // Helper function to check if two trees are exactly the same
    bool isidentical(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        return (p->val == q->val) &&
               isidentical(p->left, q->left) &&
               isidentical(p->right, q->right);
    }

    // Main function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL) return true; // Empty tree is always a subtree
        if (root == NULL) return false;   // Can't find non-empty subtree in empty tree

        // Check if the current tree starting at root is identical to subRoot
        if (isidentical(root, subRoot)) return true;

        // Otherwise, check the left and right subtrees of root
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution solution;
    bool result = solution.isSubtree(root, subRoot);
    
    cout << (result ? "subRoot is a subtree of root" : "subRoot is not a subtree of root") << endl;

    return 0;
}


