class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>cur;
        dfs(0,cur,0,candidates,target);
        return res;
    }
    void dfs(int i,vector<int>&cur,int total,vector<int>&candidates,int target){
        if(total==target){
            res.push_back(cur);
            return;
        }
        if(total>target || i==candidates.size()) return;
        cur.push_back(candidates[i]);
        dfs(i+1,cur,total+candidates[i],candidates,target);
        cur.pop_back();
        while(i+1<candidates.size()&&candidates[i]==candidates[i+1]) i++;
        dfs(i+1,cur,total,candidates,target);
    }
};
