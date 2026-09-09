class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int r = nums.size()-1,l=0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return true;
            if(nums[l]<nums[m]){
                if(target>=nums[l] && target<nums[m]){
                    r=m-1;
                }
                else l=m+1;
            }
            else if(nums[l]>nums[m]){
                if(nums[m]<target && target<=nums[r]){
                    l=m+1;
                }
                else r=m-1;
            }
            else l++;
        }
        return false;
    }
};