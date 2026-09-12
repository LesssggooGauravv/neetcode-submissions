class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int>mp;
        for(int num:hand) mp[num]++;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto&m:mp){
            pq.push(m.first);
        }
        while(!pq.empty()){
            int first = pq.top();
            for(int i=first;i<first+groupSize;i++){
                if(mp.find(i)==mp.end()) return false;
                mp[i]--;
                if(mp[i]==0){
                    if(i!=pq.top()) return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};
