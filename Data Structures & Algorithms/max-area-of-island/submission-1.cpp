class Solution {
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited, int r, int c){
        int n = grid.size();
        int m = grid[0].size();
        visited[r][c]++;
        int area = 1;
        
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++){
            int mr = r + dr[i];
            int mc = c + dc[i];

            if(mr >= 0 && mr < n && mc >= 0 && mc < m && !visited[mr][mc] && grid[mr][mc]){
                area += dfs(grid, visited, mr, mc);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = dfs(grid, visited, i, j);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
