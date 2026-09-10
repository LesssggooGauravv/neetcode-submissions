class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>subset;
        dfs(0,0,s,subset,res);
        return res;
    }

    void dfs(int j,int i,string&s,vector<string>&subset,vector<vector<string>>&res){
        if(i>=s.size()){
            if(i==j) res.push_back(subset);
            return;
        }
        if(isPali(s,j,i)){
            subset.push_back(s.substr(j,i-j+1));
            dfs(i+1,i+1,s,subset,res);
            subset.pop_back();
        }
        dfs(j,i+1,s,subset,res);
    }

    bool isPali(string&s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
};
