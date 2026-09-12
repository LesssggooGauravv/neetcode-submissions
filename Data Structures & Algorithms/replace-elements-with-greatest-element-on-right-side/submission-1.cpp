class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>res(arr.size());
        int right = -1;
        for(int i=arr.size()-1;i>=0;i--){
            res[i] = right;
            right = max(right,arr[i]);
        }
        return res;
    }
};