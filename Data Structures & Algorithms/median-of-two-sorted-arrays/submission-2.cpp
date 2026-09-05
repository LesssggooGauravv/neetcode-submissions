class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size()+nums2.size());
        for(int i=0;i<nums1.size();i++) res[i] = nums1[i];
        for(int i=0;i<nums2.size();i++) res[i+nums1.size()] = nums2[i];
        sort(res.begin(),res.end());
        if(res.size()%2==1) return res[res.size()/2];
        return (res[res.size()/2-1]+res[res.size()/2])/2.0;
    }
};
