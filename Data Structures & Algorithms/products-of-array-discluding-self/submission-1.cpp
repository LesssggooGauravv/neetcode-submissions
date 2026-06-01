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

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) mul*=nums[i];
            else zero++;
        }
        if(zero>1) return vector<int>(nums.size(),0);
        vector<int> prod(nums.size());
        for(int i=0;i<nums.size();i++){
            if(zero>0) prod[i]=(nums[i]==0) ? mul:0;
            else prod[i] = mul/nums[i];
        }
        return prod;
    }
};
