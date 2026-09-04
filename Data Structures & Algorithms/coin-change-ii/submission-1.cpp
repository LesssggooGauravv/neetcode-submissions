class Solution {
public:
    int dfs(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0) return amount%coins[i]==0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = dfs(i-1,amount,coins,dp);
        int take = 0;
        if(coins[i]<=amount) take = dfs(i,amount-coins[i],coins,dp);
        return dp[i][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int j=0;j<=amount;j++){
            dp[0][j]=(j%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = dp[i-1][j];
                int take=0;
                if(j>=coins[i]) take = dp[i][j-coins[i]];
                dp[i][j] = take+notTake;
            }
        }
        // return dfs(n-1,amount,coins,dp);
        return dp[n-1][amount];
    }
};
