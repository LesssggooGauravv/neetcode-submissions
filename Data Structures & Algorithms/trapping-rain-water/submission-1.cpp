class Solution {
public:
    int trap(vector<int>& height) {
        int maxl=0,maxr=0,l=0,r=height.size()-1,total=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<maxl) total+=maxl-height[l];
                else maxl=height[l];
                l++;
            }
            else{
                if(height[r]<maxr) total+=maxr-height[r];
                else maxr=height[r];
                r--;
            }
        }
        return total;
    }
};
