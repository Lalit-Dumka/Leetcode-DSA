class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = n-1;

        double sol = 1;
        for(int i = 1; i<=r; i++){
            sol = (sol* (N-r+i))/i;
        }

        return sol;
    }
};