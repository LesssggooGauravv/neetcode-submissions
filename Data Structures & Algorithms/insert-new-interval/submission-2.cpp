class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(auto&it:intervals){
            int start=it[0];
            int end=it[1];
            int lastend=res.back()[1];
            if(start<=lastend) res.back()[1]=max(lastend,end);
            else res.push_back(it);
        }
        return res;
    }
};
