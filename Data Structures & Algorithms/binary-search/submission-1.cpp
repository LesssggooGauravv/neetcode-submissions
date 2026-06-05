// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             if(target==nums[i]) return i;
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
