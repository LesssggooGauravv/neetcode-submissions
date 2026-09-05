class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mins=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>=target){
                    mins = min(mins,j-i+1);
                }
            }
        }
        return mins==INT_MAX?0:mins;
    }
};