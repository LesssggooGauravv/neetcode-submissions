class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        dfs(0,0,target,nums,{},res);
        return res;
    }
    void dfs(int i,int total,int target,vector<int>&nums,vector<int>subset,vector<vector<int>>&res){
        if(total==target){
            res.push_back(subset);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(total+nums[i]>target) return;
            subset.push_back(nums[j]);
            dfs(j,total+nums[j],target,nums,subset,res);
            subset.pop_back();
        }
    }
};
