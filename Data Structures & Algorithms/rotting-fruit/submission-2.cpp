class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)q.push({i, j});
            }
        }

        int time = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        bool rotten = false;

        while(!q.empty()){
            int sz = q.size();
            rotten = false;
            while(sz--){
                auto it = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = dr[i] + it.first;
                    int nc = dc[i] + it.second;
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                    if(grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        rotten = true;
                    }
                }
            }
            if(rotten) time++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};
