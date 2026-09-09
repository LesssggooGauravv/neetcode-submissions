class Solution {
public:
    void dfs(int i,vector<int>&nums,vector<int>&subset,set<vector<int>>&res){
        if(i>=nums.size()){
            res.insert(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1,nums,subset,res);
        subset.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        dfs(i+1,nums,subset,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<int>subset;
        dfs(0,nums,subset,res);
        return vector<vector<int>>(res.begin(),res.end());
    }
};
