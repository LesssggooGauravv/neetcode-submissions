class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        unordered_map<int,int>count;
        for(int n:hand) count[n]++;
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(auto&pair:count){
            minheap.push(pair.first);
        }
        while(!minheap.empty()){
            int first = minheap.top();
            for(int i=first;i<first+groupSize;i++){
                if(count.find(i)==count.end()) return false;
                count[i]--;
                if(count[i]==0){
                    if(i!=minheap.top()) return false;
                    minheap.pop();
                }
            }
        }
        return true;
    }
};
