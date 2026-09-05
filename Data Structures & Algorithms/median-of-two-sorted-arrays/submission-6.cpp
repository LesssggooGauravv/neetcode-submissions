class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        if(m<n) return findMedianSortedArrays(nums2,nums1);

        int l=0,r=n;
        while(l<=r){
            int px = l+(r-l)/2;
            int py = (n+m+1)/2-px;
            
            int l1 = (px==0) ? INT_MIN:nums1[px-1];
            int l2 = (py==0) ? INT_MIN:nums2[py-1];
            int r1 = (px==n) ? INT_MAX:nums1[px];
            int r2 = (py==m) ? INT_MAX:nums2[py];
            
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2){
                r = px-1;
            }
            else{
                l = px+1;
            }
        }
        return -1;
    }
};
