class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>subset;
        dfs(0,0,subset,res,nums,target);
        return res;
    }
    void dfs(int i, int total, vector<int>&subset, vector<vector<int>>&res,vector<int>&nums,int target){
        if(target==total){
            res.push_back(subset);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(total+nums[j]>target) break;
            subset.push_back(nums[j]);
            dfs(j,total+nums[j],subset,res,nums,target);
            subset.pop_back();
        }
    }
};
