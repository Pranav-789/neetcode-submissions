class Solution {
    const int INF = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int i = it.first, j = it.second;
            for(int p = 0; p < 4; p++){
                int nr = i + dr[p];
                int nc = j + dc[p];

                if(nc < 0 || nc >= m || nr < 0 || nr >= n) continue;
                if(grid[nr][nc] == -1) continue;
                if(grid[nr][nc] == INF){
                    grid[nr][nc] = grid[i][j]+1;
                    q.push({nr, nc});
                }
            }
        }
        return;
    }
};
