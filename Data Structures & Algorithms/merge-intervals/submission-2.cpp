class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(auto&interval:intervals){
            int start = interval[0];
            int end = interval[1];
            int lastend = res.back()[1];
            if(start<=lastend){
                res.back()[1] = max(lastend,end);
            }
            else{
                res.push_back({start,end});
            }
        }
        return res;
    }
};
