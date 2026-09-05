class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mins=INT_MAX;
        int l=0,r=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>=target){
                mins = min(r-l+1,mins);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return mins==INT_MAX?0:mins;
    }
};