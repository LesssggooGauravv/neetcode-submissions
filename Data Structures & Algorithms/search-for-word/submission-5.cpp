class Solution {
public:
    set<pair<int,int>>path;
    int n,m;

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(),m=board[0].size();
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(dfs(0,r,c,board,word)) return true;
            }
        }    
        return false;
    }

    bool dfs(int i,int r,int c,vector<vector<char>>&board,string&word){
        if(i==word.size()) return true;
        if(r<0 || c<0 || r>=n || c>=m || board[r][c]!=word[i] || path.count({r,c})) return false;
        path.insert({r,c});
        bool res = dfs(i+1,r+1,c,board,word) ||
                    dfs(i+1,r-1,c,board,word) ||
                    dfs(i+1,r,c+1,board,word) ||
                    dfs(i+1,r,c-1,board,word);
        path.erase({r,c});
        return res;
    }
};
