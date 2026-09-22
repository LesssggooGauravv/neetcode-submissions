class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x,res=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if((long long)m*m==x) return m;
            else if((long long)m*m<x){
                l=m+1;
                res=m;
            }
            else r=m-1;
        }
        return res;
    }
};