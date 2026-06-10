class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i;j<prices.size();j++){
                prof = max(prof, prices[j]-prices[i]);
            }
        }
        return prof;
    }
};
