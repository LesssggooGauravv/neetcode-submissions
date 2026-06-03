// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++){
//             int temp = target-nums[i];
//             if(mp.count(temp)) return {mp[temp],i+1};
//             mp[nums[i]]=i+1;
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum>target) r--;
            else if(sum<target) l++;
            else return {l+1,r+1};
        }
        return {};
    }
};
