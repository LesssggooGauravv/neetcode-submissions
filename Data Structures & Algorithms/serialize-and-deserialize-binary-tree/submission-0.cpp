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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(!node) s.append("null,");
            else s.append(to_string(node->val)+",");
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream s(data);
        string val;
        getline(s,val,',');
        TreeNode*root = new TreeNode(stoi(val));
        queue<TreeNode*>q;
        q.push(root);
        while(getline(s,val,',')){
            TreeNode* node = q.front(); q.pop();
            if(val!="null"){
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(s,val,',');
            if(val!="null"){
                node->right=new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
