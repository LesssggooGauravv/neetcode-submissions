// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         vector<int> ans(temp.size(),0);
//         for(int i=0;i<temp.size();i++){
//             for(int j=i+1;j<temp.size();j++){
//                 if(temp[i]<temp[j]){
//                     ans[i]=j-i;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        for(int i=n-2;i>=0;i--){
            int j=i+1;
            while(j<n && temp[j]<=temp[i]){
                if(ans[j]==0){
                    j=n;
                    break;
                }
                j+=ans[j];
            }
            if(j<n) ans[i]=j-i;
        }
        return ans;
    }
};
