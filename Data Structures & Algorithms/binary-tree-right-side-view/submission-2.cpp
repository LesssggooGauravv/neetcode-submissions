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
    vector<int>res;
    void check(TreeNode*root,int depth){
        if(!root) return;
        if(res.size()==depth) res.push_back(root->val);
        check(root->right,depth+1);
        check(root->left,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        check(root,0);
        return res;
    }
};
