class Solution {
public:
    void dfs(int i,int target,vector<int>&nums,vector<int>&subset,vector<vector<int>>&res){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        subset.push_back(nums[i]);
        dfs(i,target-nums[i],nums,subset,res);
        subset.pop_back();
        dfs(i+1,target,nums,subset,res);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>subset;
        dfs(0,target,nums,subset,res);
        return res;
    }
};
