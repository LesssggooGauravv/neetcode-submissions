class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n<m) return "";
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++) mp[t[i]]++;
        int r=0, l=0, cnt=0;
        int minlen = INT_MAX, sIndex = -1;
        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            r++;
            while(cnt==m){
                if(r-l<minlen){
                    minlen=r-l;
                    sIndex=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
        }
        return sIndex == -1? "":s.substr(sIndex,minlen);
    }
};
