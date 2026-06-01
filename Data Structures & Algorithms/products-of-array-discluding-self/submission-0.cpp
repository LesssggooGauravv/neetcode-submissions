class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod;
        for(int i=0;i<nums.size();i++){
            int mul=1;
            for(int j=0;j<nums.size();j++){
                if(j==i) continue;
                mul*=nums[j];
            }
            prod.push_back(mul);
        }
        return prod;
    }
};
