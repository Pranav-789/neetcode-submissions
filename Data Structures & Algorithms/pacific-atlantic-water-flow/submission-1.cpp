class Solution {
    void dfs(
        vector<vector<int>>& heights,
        vector<vector<int>>& visited,
        int i, int j
    ){
        int n = heights.size();
        int m = heights[0].size();

        visited[i][j] = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int it = 0; it < 4; it++){
            int nr = dr[it] + i;
            int nc = dc[it] + j;

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            
            if(!visited[nr][nc] && heights[nr][nc] >= heights[i][j])
                dfs(heights, visited, nr, nc);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visited1(n, vector<int>(m, 0));
        vector<vector<int>> visited2(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(!visited1[0][i]) dfs(heights, visited1, 0, i);
        }
        for(int i = 0; i < n; i++){
            if(!visited1[i][0]) dfs(heights, visited1, i, 0);
        }


        for(int i = 0; i < m; i++){
            if(!visited2[n-1][i]) dfs(heights, visited2, n-1, i);
        }

        for(int i = 0; i < n; i++){
            if(!visited2[i][m-1]) dfs(heights, visited2, i, m-1);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited1[i][j] == 1 && visited2[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
