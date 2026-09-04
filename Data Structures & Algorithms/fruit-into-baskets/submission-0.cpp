class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=0;
        for(int i=0;i<fruits.size();i++){
            unordered_set<int>st;
            for(int j=i;j<fruits.size();j++){
                st.insert(fruits[j]);
                if(st.size()<=2) maxlen = max(maxlen,j-i+1);
                else break;
            }
        }
        return maxlen;
    }
};