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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode*node=root;
        while(node){
            if(node->right==NULL){
                res.push_back(node->val);
                node=node->left;
            }
            else{
                TreeNode*prev=node->right;
                while(prev->left && prev->left!=node){
                    prev=prev->left;
                }
                if(!prev->left){
                    res.push_back(node->val);
                    prev->left=node;
                    node=node->right;
                }
                else{
                    prev->left=nullptr;
                    node=node->left;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};