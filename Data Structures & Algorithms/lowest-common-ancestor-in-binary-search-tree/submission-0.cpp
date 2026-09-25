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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        dfs(root, p, path1);
        dfs(root, q, path2);
        path1.push_back(p);
        path2.push_back(q);

        TreeNode* ancestor = root; 

        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i]->val == path2[i]->val)
                ancestor = path1[i];
            else break;
        }

        return ancestor;
    }

    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr)
            return false;
        if (root == target)
            return true;

        path.push_back(root);
        
        bool result = dfs(root->left, target, path);
        if (result) {
            return true;
        }
        result = dfs(root->right, target, path);
        if (result) {
            return true;
        }

        path.pop_back();
        
        return false;
    }
};
