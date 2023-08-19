class Solution {
    int checkPath(vector<vector<int>> &dp, int m, int n, int i, int j){
        if(i>=m || j>= n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = checkPath(dp, m,n,i+1,j) + checkPath(dp, m,n,i,j+1);
        
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        return checkPath(dp,m,n,0,0);
    }
};