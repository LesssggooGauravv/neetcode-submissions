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
    void dfs(int i,TreeNode*root,vector<int>&res){
        if(!root) return;
        if(i==res.size()) res.push_back(root->val);
        dfs(i+1,root->right,res);
        dfs(i+1,root->left,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        dfs(0,root,res);
        return res;
    }
};
