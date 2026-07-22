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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode*root,int&res){
        if(!root) return 0;
        int left = dfs(root->left,res);
        left = max(left,0);
        int right = dfs(root->right,res);
        right = max(right,0);
        res = max(res,root->val+left+right);
        return root->val + max(left,right);
    }
};
