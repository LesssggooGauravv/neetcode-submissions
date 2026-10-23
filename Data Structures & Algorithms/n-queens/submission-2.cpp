class Solution {
public:
    vector<vector<string>>res;
    int m;

    bool isValid(vector<string>&board,int row,int col){
        //look upward
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        //left diagonal upward
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //right diagonal upward
        for(int i=row-1,j=col+1;i>=0 && j<m;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }

    void solve(vector<string>&board,int row){
        if(row>=m) {
            res.push_back(board);
            return;
        }
        for(int col=0;col<m;col++){
            if(isValid(board,row,col)){
                board[row][col]='Q';
                solve(board,row+1);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        m=n;
        vector<string>board(n,string(n,'.'));
        solve(board,0);
        return res;
    }
};
