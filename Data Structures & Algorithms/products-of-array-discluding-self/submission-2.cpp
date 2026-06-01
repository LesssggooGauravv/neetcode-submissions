// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> prod;
//         for(int i=0;i<nums.size();i++){
//             int mul=1;
//             for(int j=0;j<nums.size();j++){
//                 if(j==i) continue;
//                 mul*=nums[j];
//             }
//             prod.push_back(mul);
//         }
//         return prod;
//     }
// };

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int mul=1;
//         int zero=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=0) mul*=nums[i];
//             else zero++;
//         }
//         if(zero>1) return vector<int>(nums.size(),0);
//         vector<int> prod(nums.size());
//         for(int i=0;i<nums.size();i++){
//             if(zero>0) prod[i]=(nums[i]==0) ? mul:0;
//             else prod[i] = mul/nums[i];
//         }
//         return prod;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0] = 1;
        suff[n-1] = 1;
        for(int i=1;i<n;i++) 
            pref[i] = nums[i-1]*pref[i-1];
        for(int i=n-2;i>=0;i--) 
            suff[i] = nums[i+1]*suff[i+1];
        for(int i=0;i<n;i++)
            res[i] = pref[i]*suff[i];
        return res;
    }
};