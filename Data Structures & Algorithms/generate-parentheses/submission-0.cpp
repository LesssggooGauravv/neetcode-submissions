class Solution {
public:
    void dfs(int i,int j, int n, vector<string>&res,string&stack){
        if(i==j && i==n){
            res.push_back(stack);
            return;
        }
        if(i<n){
            stack+='(';
            dfs(i+1,j,n,res,stack);
            stack.pop_back();
        }
        if(j<i){
            stack+=')';
            dfs(i,j+1,n,res,stack);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string stack;
        dfs(0,0,n,res,stack);
        return res;
    }
};
