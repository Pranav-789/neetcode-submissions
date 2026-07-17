class Solution {
    bool dfs(int src, vector<vector<int>> &graph, vector<int>& visited, vector<int>& inPath){
        visited[src] = 1;
        inPath[src] = 1;
        for(int i: graph[src]){
            if(inPath[i] == 1) return false;
            if(visited[i]) continue;
            if(!dfs(i, graph, visited, inPath)) return false;
        }
        inPath[src] = 0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> inPath(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(!dfs(i, graph, visited, inPath)) return false;
            }
        }
        return true;
    }
};
