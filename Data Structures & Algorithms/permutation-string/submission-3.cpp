class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map<char,int>count1;
        for(int i=0;i<s1.size();i++){
            count1[s1[i]]++;
        }
        int need = count1.size();
        for(int i=0;i<s2.size();i++){
            unordered_map<char,int> count2;
            int cur=0;
            for(int j=i;j<s2.size();j++){
                count2[s2[j]]++;
                if(count1[s2[j]]<count2[s2[j]]) break;
                if(count1[s2[j]]==count2[s2[j]]) cur++;
                if(cur==need) return true;
            }
        }
        return false;
    }
};
