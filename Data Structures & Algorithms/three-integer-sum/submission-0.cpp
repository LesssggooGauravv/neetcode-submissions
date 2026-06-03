class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0)
                        res.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1]) continue;
//             int l=i+1, r=nums.size()-1;
//             while(l<r){
//                 int sum=nums[l]+nums[r];
//                 if(sum<0) l++;
//                 else if(sum>0) r--;
//                 else return {{l+1,r+1}};
//             }
//         }
//     }
// };
