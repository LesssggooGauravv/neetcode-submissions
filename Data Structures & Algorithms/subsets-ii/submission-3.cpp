class Solution {
public:
    void dfs(int i,vector<int>&nums,vector<int>&subset,set<vector<int>>&res){
        if(i>=nums.size()){
            vector<int>temp = subset;
            sort(temp.begin(),temp.end());
            res.insert(temp);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1,nums,subset,res);
        subset.pop_back();
        dfs(i+1,nums,subset,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res;
        vector<int>subset;
        dfs(0,nums,subset,res);
        return vector<vector<int>>(res.begin(),res.end());
    }
};
