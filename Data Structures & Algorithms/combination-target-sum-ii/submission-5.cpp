class Solution {
public:
    void dfs(int i,int target,vector<int>&nums,vector<int>&subset,vector<vector<int>>&res){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target<0 || i>=nums.size()) return;
        subset.push_back(nums[i]);
        dfs(i+1,target-nums[i],nums,subset,res);
        subset.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        dfs(i+1,target,nums,subset,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>subset;
        dfs(0,target,nums,subset,res);
        return res;
    }
};
