// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int speed=1;
//         while(true){
//             long long time = 0;
//             for(int pile:piles){
//                 time+=(pile+speed-1)/speed;
//             }
//             if(time<=h) return speed;
//             speed++;
//         }
//     }
// };


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int res = r;
        while(l<=r){
            int k = l + (r-l)/2;
            long long time=0;
            for(int p:piles){
                time+=ceil(static_cast<double>(p)/k);
            }
            if(time<=h){
                res=k;
                r=k-1;
            }
            else{
                l=k+1;
            }
        }
        return res;
    }
};
