// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         for(int i:nums){
//             mp[i]++;
//         }

//         vector<pair<int,int>> arr;
//         for(const auto&p:mp){
//             arr.push_back({p.second,p.first});
//         }
//         sort(arr.rbegin(),arr.rend());

//         vector<int>ans;
//         for(int i=0;i<k;i++){
//             ans.push_back(arr[i].second);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<vector<int>> freq(nums.size()+1);
        for(int i:nums){
            mp[i] = 1+mp[i];
        }
        for(const auto& c:mp){
            freq[c.second].push_back(c.first);
        }
        vector<int> res;
        for(int i=freq.size()-1;i>0;i--){
            for(int n:freq[i]){
                res.push_back(n);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};
