class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>res(arr.size());
        for(int i=1;i<arr.size();i++){
            res[i-1] = *max_element(arr.begin()+i,arr.end());
        }
        res[arr.size()-1] = -1;
        return res;
    }
};