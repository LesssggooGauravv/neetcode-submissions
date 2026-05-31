class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi=1;
        int cnt=0;
        int last=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == last){
                cnt++;
                last = nums[i];
            }
            else if(nums[i]!=last){
                cnt = 1;
                last = nums[i];
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};