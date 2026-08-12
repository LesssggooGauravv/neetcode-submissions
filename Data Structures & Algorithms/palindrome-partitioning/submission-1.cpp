class Solution {
public:
    bool isPali(string&s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void dfs(int i, string&s, vector<string>&subset,vector<vector<string>>&res){
        if(i==s.size()){
            res.push_back(subset);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPali(s,i,j)){
                subset.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,subset,res);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>subset;
        dfs(0,s,subset,res);
        return res;
    }
};
