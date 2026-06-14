// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int res=0;
//         for(int i=0;i<s.size();i++){
//             unordered_set<char>charSet;
//             for(int j=i;j<s.size();j++){
//                 if(charSet.find(s[j])!=charSet.end()) break;
//                 charSet.insert(s[j]);
//             }
//             res = max(res,(int)charSet.size());
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int res=0, l=0;
//         unordered_set<char>charSet;
//         for(int r=0;r<s.size();r++){
//             while(charSet.find(s[r])!=charSet.end()){
//                 charSet.erase(s[l]);
//                 l++;
//             }
//             charSet.insert(s[r]);
//             res = max(res,r-l+1);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0, l=0;
        unordered_map<char,int>mp;
        for(int r=0;r<s.size();r++){
            if(mp.find(s[r])!=mp.end()){
                l = max(mp[s[r]]+1,l);
            }
            mp[s[r]] = r;
            res = max(res,r-l+1);
        }
        return res;
    }
};