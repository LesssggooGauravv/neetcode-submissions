class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int minp=INT_MAX;
        for(int p:prices){
            minp = min(minp,p);
            maxp = max(maxp,p-minp);
        }
        return maxp;
    }
};
