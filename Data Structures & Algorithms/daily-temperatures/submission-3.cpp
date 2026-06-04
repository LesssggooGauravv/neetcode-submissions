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


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         int n = temp.size();
//         vector<int> res(n,0);
//         stack<pair<int,int>>stack; //{temp[i],i}
//         for(int i=0;i<n;i++){
//             int t = temp[i];
//             while(!stack.empty() && t>stack.top().first){
//                 auto pair=stack.top();
//                 stack.pop();
//                 res[pair.second] = i-pair.second;
//             }
//             stack.push({t,i});
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n,0);
        stack<int>stack; //{temp[i],i}
        for(int i=0;i<n;i++){
            while(!stack.empty() && temp[i]>temp[stack.top()]){
                int idx=stack.top();stack.pop();
                res[idx] = i-idx;
            }
            stack.push(i);
        }
        return res;
    }
};
