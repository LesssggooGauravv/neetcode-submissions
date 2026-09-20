class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k==arr.size()) return arr;
        vector<int>res;
        vector<bool>used(arr.size(),false);
        while(k--){
            int mindiff=INT_MAX;
            int minele=-1;
            int mindex=-1;
            for(int i=0;i<arr.size();i++){
                if(!used[i] && abs(x-arr[i])<mindiff){
                    mindiff = abs(x-arr[i]);
                    minele = arr[i];
                    mindex = i;
                }
            }
            used[mindex] = true;
            res.push_back(minele);
        }
        sort(res.begin(),res.end());
        return res;
    }
};