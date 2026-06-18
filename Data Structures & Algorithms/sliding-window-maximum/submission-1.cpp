class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // if(nums.size()==k) return nums;
        vector<int>res;
        for(int i=0;i<=nums.size()-k;i++){
            int max1=INT_MIN;
            for(int j=i;j<i+k;j++){
                max1 = max(nums[j],max1);
            }
            res.push_back(max1);
        }
        return res;
    }
};
