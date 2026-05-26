class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // if(strs.size()==1 || strs.size()==0) return strs;

        unordered_map<string,vector<string>>res;
        for(const auto&s:strs){
            string sortedS = s;
            sort(sortedS.begin(),sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>>result;
        for(auto& pair:res){
            result.push_back(pair.second);
        }
        return result;
    }
};
