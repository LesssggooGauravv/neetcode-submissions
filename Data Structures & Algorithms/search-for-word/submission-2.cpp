class Solution {
public:
    int rows,cols;
    set<pair<int,int>>path;
    bool dfs(int i, int r,int c,vector<vector<char>>&board,string word){
        if(i==word.size()) return true;
        if(r<0 || c<0 || r>=rows || c>= cols || board[r][c]!=word[i] || path.count({r,c})) return false;
        path.insert({r,c});
        bool res = dfs(i+1,r+1,c,board,word) ||
                    dfs(i+1,r-1,c,board,word) ||
                    dfs(i+1,r,c+1,board,word) ||
                    dfs(i+1,r,c-1,board,word);
        path.erase({r,c});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(),cols = board[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(dfs(0,r,c,board,word))return true;
            }
        }
        return false;
    }
};
