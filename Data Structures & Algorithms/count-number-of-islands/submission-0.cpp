class Solution {
    void dfs(vector<vector<int>>& visited, int srci, int srcj, vector<vector<char>>& grid){
        int n = visited.size(), m = visited[0].size();
        if(srci < 0 || srci >= n || srcj < 0 || srcj >= m) return;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        visited[srci][srcj] = 1;

        for(int i = 0; i < 4; i++){
            int mr = srci + dr[i];
            int mc = srcj + dc[i];
            if(mr >= 0 && mr < n && mc >= 0 && mc < m && !visited[mr][mc] &&grid[mr][mc] == '1'){
                dfs(visited, mr, mc, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // for adjacency we will go for both dfs approach and bfs approach
        // we will require a visited to mark all the unvisited nodes;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> visited(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(visited, i, j, grid);
                }
            }
        }
        return ans;
    }
};
