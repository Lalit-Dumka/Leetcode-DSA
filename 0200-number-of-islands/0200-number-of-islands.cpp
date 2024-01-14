class Solution {
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col){
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        q.push({row,col});
        vis[row][col]=1;
        
        vector<int> del_row = {-1,1,0,0};
        vector<int> del_col = {0,0,-1,1};
        while(!q.empty()){
            int cur_row = q.front().first;
            int cur_col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int new_row = cur_row+del_row[i];
                int new_col = cur_col+del_col[i];
                if(new_row>=0 && new_row<n && new_col >=0 && new_col<m && grid[new_row][new_col]=='1' && vis[new_row][new_col]==0){
                    vis[new_row][new_col] = 1;
                    q.push({new_row,new_col});
                }
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int sol=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(grid,vis,i,j);
                    sol++;
                }
            }
        }
        return sol;
    }
};