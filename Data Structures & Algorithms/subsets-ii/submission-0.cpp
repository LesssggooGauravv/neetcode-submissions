class Solution {
public:
    set<vector<int>>res;
    vector<int>subset;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return vector<vector<int>>(res.begin(),res.end());
    }
    void dfs(int i,vector<int>&nums){
        if(i>=nums.size()){
            res.insert(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1,nums);
        subset.pop_back();
        dfs(i+1,nums);
    }
};
