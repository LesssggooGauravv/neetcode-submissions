class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap;
        for(int s:stones) maxheap.push(s);
        while(maxheap.size()>1){
            int i = maxheap.top(); maxheap.pop();
            int j = maxheap.top(); maxheap.pop();
            if(j<i) maxheap.push(i-j);
        }
        maxheap.push(0);
        return maxheap.top();
    }
};
