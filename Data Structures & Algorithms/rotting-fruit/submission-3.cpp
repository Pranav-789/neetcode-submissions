class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1) fresh++;
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
                        fresh--;
                        if(fresh == 0) return time+1;
                    }
                }
            }
            if(rotten) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
