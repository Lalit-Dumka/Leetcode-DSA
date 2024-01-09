class Solution {
    bool isSafe(int n, vector<string> &cur, int row, int col){
        int row_copy = row, col_copy = col;
        while(row >=0 && col >=0){
            if(cur[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row=row_copy, col = col_copy;
        while(col >=0 ){
            if(cur[row][col]=='Q') return false;
            col--;
        }
        
        row = row_copy, col = col_copy;
        while(row<n && col>=0){
            if(cur[row][col]=='Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void f(int n, int col, vector<string> &cur, vector<vector<string>> &sol){
        if(col>=n){
            sol.push_back(cur);
            return;
        }
        
        for(int row = 0; row<n; row++ ){
            if(isSafe(n, cur, row, col)){
                cur[row][col]='Q';
                f(n,col+1,cur,sol);
                cur[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> cur(n);
        string s(n,'.');
        for(int i = 0; i<n; i++){
            cur[i]=s;
        }
        f(n, 0, cur, sol);
        
        return sol;
    }
};