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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode*node=root;
        while(node){
            if(node->left==NULL){
                res.push_back(node->val);
                node=node->right;
            }
            else{
                TreeNode*lchild = node->left;
                while(lchild->right){
                    lchild=lchild->right;
                }
                lchild->right=node;
                TreeNode*temp=node;
                node=node->left;
                temp->left=NULL;
            }
        }
        return res;
    }
};