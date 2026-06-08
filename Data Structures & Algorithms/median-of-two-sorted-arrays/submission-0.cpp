// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>nums;
//         for(int i=0;i<nums1.size();i++){
//             nums.push_back(nums1[i]);
//         }
//         for(int i=0;i<nums2.size();i++){
//             nums.push_back(nums2[nums1.size()+i]);
//         }
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         if(n%2!=0){
//             return (double)(nums[n/2+1]);
//         }
//         else{
//             return (double)((nums[n/2-1]+nums[n/2])/2);
//         }
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2 = nums2.size();
        vector<int>nums(l1+l2);
        copy(nums1.begin(),nums1.end(),nums.begin());
        copy(nums2.begin(),nums2.end(),nums.begin()+l1);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n%2!=0){
            return (double)(nums[n/2]);
        }
        else{
            return (double)((nums[n/2-1]+nums[n/2])/2.0);
        }
    }
};
