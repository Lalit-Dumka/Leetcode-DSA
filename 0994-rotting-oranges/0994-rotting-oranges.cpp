class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        int sol = 0;
        
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        vector<int> del_row = {0, 0, -1, 1};
        vector<int> del_col = {-1, 1, 0, 0};
        
        
        while(!q.empty()){
            int cur_row = q.front().first.first;
            int cur_col = q.front().first.second;
            
            int cur_time = q.front().second;
            
            sol = max(sol, cur_time);
            q.pop();
            
            for(int i = 0; i< 4; i++){
                int new_row = cur_row + del_row[i];
                int new_col = cur_col + del_col[i];
                if(new_row >=0 && new_row<n && new_col>=0 && new_col<m && vis[new_row][new_col]!=1 && grid[new_row][new_col] == 1){
                    q.push({{new_row,new_col},cur_time+1});
                    vis[new_row][new_col]= 1;
                    
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    return -1;
                }
            }
        }
        
        
        return sol;
    }
};