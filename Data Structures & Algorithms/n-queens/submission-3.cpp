class Solution {
public:
    vector<vector<string>>res;
    int m;
    unordered_set<int>cols;
    unordered_set<int>diag;
    unordered_set<int>antidiag;
    
    void solve(vector<string>&board,int row){
        if(row>=m){
            res.push_back(board);
            return;
        }
        for(int col=0;col<m;col++){
            int diagConst = row+col;
            int antiDiagConst = row-col;
            if(cols.find(col)!=cols.end() || diag.find(diagConst)!=diag.end() || antidiag.find(antiDiagConst)!=antidiag.end()){
                continue;
            }
            
            cols.insert(col);
            diag.insert(diagConst);
            antidiag.insert(antiDiagConst);
            board[row][col] = 'Q';
            
            solve(board,row+1);
            
            cols.erase(col);
            diag.erase(diagConst);
            antidiag.erase(antiDiagConst);
            board[row][col] = '.';
            
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        m=n;
        vector<string>board(n,string(n,'.'));
        
        solve(board,0);
        return res;
    }
};
