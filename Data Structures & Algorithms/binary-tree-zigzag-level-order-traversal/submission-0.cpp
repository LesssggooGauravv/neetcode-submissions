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
    vector<vector<int>>res;
    void level(TreeNode*root,int i){
        if(!root) return;
        if(i==res.size()) res.push_back({});
        if(i%2==0) res[i].push_back(root->val);
        else res[i].insert(res[i].begin(),root->val);
        level(root->left,i+1);
        level(root->right,i+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        level(root,0);
        return res;
    }
};