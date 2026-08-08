/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
    
        stack<TreeNode> nodestack;

        return max(depthRecursive(root->left, 1), depthRecursive(root->right, 1));
    }

    int depthRecursive(TreeNode* node, int height) {
        if (!node)
            return height;

        return max(depthRecursive(node->left, height+1), depthRecursive(node->right, height+1));
    }
};
