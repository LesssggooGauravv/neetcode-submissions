// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l=0,r=nums.size();
//         while(l<r){
//             int m=l+(r-l)/2;
//             if(nums[m]==target){
//                 return m;
//             }
//             else if(nums[m]<nums[r]){

//             }
//         }
//     }
// };


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};
