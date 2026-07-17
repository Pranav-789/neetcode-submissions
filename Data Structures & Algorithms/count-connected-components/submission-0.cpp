class Solution {
    void dfs(int src, vector<vector<int>>& graph, vector<int>& visited){
        visited[src] = 1;

        for(auto adj: graph[src]){
            if(!visited[adj]){
                dfs(adj, graph, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, graph, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
