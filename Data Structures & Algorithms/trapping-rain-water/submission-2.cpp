class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l=0,r=height.size()-1;
        int lmax=height[l],rmax=height[r];
        int sum=0;
        while(l<r){
            if(lmax<rmax){
                l++;
                lmax=max(height[l],lmax);
                sum+=lmax-height[l];
            }
            else{
                r--;
                rmax=max(height[r],rmax);
                sum+=rmax-height[r];
            }
        }
        return sum;
    }
};
