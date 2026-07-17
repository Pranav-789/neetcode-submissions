class Solution {
    bool dfs(int src, int parent, vector<vector<int>>& graph, vector<int>& visited){
        visited[src] = 1;

        for(auto adj: graph[src]){
            if(adj != parent && visited[adj]) return false;
            if(!visited[adj]){
                if(!dfs(adj, src, graph, visited)) return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        bool ans = dfs(0, -1, graph, visited);

        if(!ans) return false;

        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
