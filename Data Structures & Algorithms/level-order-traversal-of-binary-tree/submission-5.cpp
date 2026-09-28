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
    void level(int i,TreeNode*root,vector<vector<int>>&res){
        if(!root) return;
        if(i==res.size()) res.push_back(vector<int>());
        res[i].push_back(root->val);
        level(i+1,root->left,res);
        level(i+1,root->right,res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        level(0,root,res);
        return res;
    }
};
