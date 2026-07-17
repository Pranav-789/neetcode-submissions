class Solution {
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& visited, vector<int>& inPath, vector<int>& ans){
        visited[src] = 1;
        inPath[src] = 1;
        
        for(auto adj: graph[src]){
            if(inPath[adj]) return false;
            if(visited[adj]) continue;
            if(!dfs(adj, graph, visited, inPath, ans)) return false;
        }
        
        inPath[src] = 0;
        ans.push_back(src);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> ans;
        
        vector<int> visited(numCourses, 0);
        vector<int> inPath(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(!dfs(i, graph, visited, inPath, ans)) return {};
            }   
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
