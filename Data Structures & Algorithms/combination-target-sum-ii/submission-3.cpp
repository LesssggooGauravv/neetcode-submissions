class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        vector<int>subset;
        dfs(0,0,subset,res,nums,target);
        return res;
    }
    void dfs(int i,int total,vector<int>&subset,vector<vector<int>>&res,vector<int>&nums,int target){
        if(target==total){
            res.push_back(subset);
            return;
        }
        if(total>target||i==nums.size()) return;
        subset.push_back(nums[i]);
        dfs(i+1,total+nums[i],subset,res,nums,target);
        subset.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        dfs(i+1,total,subset,res,nums,target);
    }
};
