class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxheap;
        for(int i=0;i<points.size();i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxheap.push({dist,{points[i][0],points[i][1]}});
            if(maxheap.size()>k) maxheap.pop();
        }
        vector<vector<int>>res;
        while(!maxheap.empty()){
            res.push_back({maxheap.top().second.first,maxheap.top().second.second});
            maxheap.pop();
        }
        return res;
    }
};
