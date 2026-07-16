class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j){
        int n = board.size();
        int m = board[0].size();

        visited[i][j] = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int p = 0; p < 4; p++){
            int nr = i + dr[p];
            int nc = j + dc[p];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            if(!visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(board, visited, nr, nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(!visited[0][i] && board[0][i] == 'O') dfs(board, visited, 0, i);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i][0] && board[i][0] == 'O') dfs(board, visited, i, 0);
        }

        for(int i = 0; i < m; i++){
            if(!visited[n-1][i] && board[n-1][i] == 'O') dfs(board, visited, n-1, i);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i][m-1] && board[i][m-1] == 'O') dfs(board, visited, i, m-1);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
