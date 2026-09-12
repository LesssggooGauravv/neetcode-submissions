class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        vector<string>mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty()) return res;
        dfs(0,"",mapping,res,digits);
        return res;
    }

    void dfs(int i,string subset,vector<string>&mapping,vector<string>&res,string&digits){
        if(subset.size()==digits.size()){
            res.push_back(subset);
            return;
        }
        string chars = mapping[digits[i]-'0'];
        for(char c:chars){
            dfs(i+1,subset+c,mapping,res,digits);
        }
    }
};
