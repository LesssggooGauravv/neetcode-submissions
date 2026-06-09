class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        int l=0;
        unordered_map<char,int>freq;
        int maxf=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            maxf = max(maxf,freq[s[r]]);
            while((r-l+1)-maxf>k){
                freq[s[l]]--;
                l++;
            }
            res = max(r-l+1,res);
        }
        return res;
    }
};
