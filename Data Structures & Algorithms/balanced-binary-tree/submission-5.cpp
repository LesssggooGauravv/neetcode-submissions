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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftH = height(root->left);
        int rightH=height(root->right);
        if(abs(leftH-rightH)>1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left||!right) return false;
        return true;
    }
    int height(TreeNode*root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
};
