class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        // q.push({0, {0, 0}});

        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];
        q.push({grid[0][0], {0,0}});

        while(!q.empty()){
            int i = q.top().second.first;
            int j = q.top().second.second;
            int t = q.top().first;
            q.pop();

            for(int p = 0; p < 4; p++){
                int nr = i + dr[p];
                int nc = j + dc[p];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                // if(dist[nr][nc] != -1) continue;

                int newt = max(t, grid[nr][nc]);
                if(newt < dist[nr][nc]){
                    dist[nr][nc] = newt;
                    q.push({newt,{nr,nc}});
                }   
            }
        }

        return dist[n-1][n-1];
    }
};