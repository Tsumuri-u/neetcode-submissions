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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> nodes;
        nodes.push(root);

        TreeNode* curr;
        while(!nodes.empty()) {
            curr = nodes.front();
            nodes.pop();

            if (curr->left)
                nodes.push(curr->left);
            if (curr->right)
                nodes.push(curr->right);

            TreeNode* tempLeft = curr->left;
            curr->left = curr->right;
            curr->right = tempLeft;            
        }

        return root;
    }
};
