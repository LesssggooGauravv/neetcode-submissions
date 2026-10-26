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
    void dfs(int i,TreeNode*root,vector<vector<int>>&res){
        if(!root) 
            return;

        if(res.size()==i)
            res.push_back({});
        
        res[i].push_back(root->val);
        dfs(i+1,root->left,res);
        dfs(i+1,root->right,res);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        dfs(0,root,res);
        for(int i=0;i<res.size();i++){
            if(i%2!=0){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};