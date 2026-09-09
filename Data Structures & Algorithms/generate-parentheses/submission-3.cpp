class Solution {
public:
    void dfs(int open, int close,int n,string&stack,vector<string>&res){
        if(open==close && open==n){
            res.push_back(stack);
            return;
        }
        if(open<n){
            stack+='(';
            dfs(open+1,close,n,stack,res);
            stack.pop_back();
        }
        if(close<open){
            stack+=')';
            dfs(open,close+1,n,stack,res);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string stack;
        dfs(0,0,n,stack,res);
        return res;
    }
};
