class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==m-1)
            return dp[i][j] = grid[i][j] + solve(grid,i,j+1,dp);
        else if(j==n-1)
            return dp[i][j] = grid[i][j] + solve(grid,i+1,j,dp);
        else
            return dp[i][j] = grid[i][j] + min(solve(grid,i,j+1,dp),solve(grid,i+1,j,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(grid,0,0,dp);
    }
};