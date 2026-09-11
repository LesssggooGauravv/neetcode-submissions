class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int a = stones[stones.size()-1];
            int b = stones[stones.size()-2];
            stones.pop_back();
            stones.pop_back();
            int diff = a-b;
            if(diff!=0)stones.push_back(diff);
        }
        return (stones.empty())?0:stones[0];
    }
};
