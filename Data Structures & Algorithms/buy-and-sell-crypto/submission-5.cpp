// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int prof=0;
//         for(int i=0;i<prices.size();i++){
//             for(int j=i;j<prices.size();j++){
//                 prof = max(prof, prices[j]-prices[i]);
//             }
//         }
//         return prof;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=0;
        int prof=0;
        while(r<prices.size()){
            if(prices[l]>prices[r]){
                l++;
            }
            else{
                prof = max(prof,prices[r]-prices[l]);
                r++;
            }
        }
        return prof;
    }
};
