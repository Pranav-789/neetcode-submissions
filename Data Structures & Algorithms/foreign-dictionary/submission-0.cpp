class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_map<char, vector<char>> graph;

        for (auto &word : words) {
            for (char c : word)
                graph[c];
        }

        if(n == 1) return words[0];

        for(int i = 0; i < n - 1; i++){
            string cstr = words[i];
            string nstr = words[i+1];
            int cs = cstr.size(), ns = nstr.size();

            int j = 0;
            while(j < cs && j < ns && cstr[j] == nstr[j]) j++;
            if (j == ns && cs > ns)
                return "";
            if(j < cs && j < ns) graph[cstr[j]].push_back(nstr[j]);
        }

        int V = graph.size();

        unordered_map<char, int> visited;
        unordered_map<char, int> inPath;

        for(auto it: graph){
            visited[it.first] = 0;
            inPath[it.first] = 0;
        }

        string ans;

        for(auto it: visited){
            if(!it.second){
                if(!dfs(it.first, graph, visited, inPath, ans)) return {};
            }
        }     
        reverse(ans.begin(), ans.end());
        return ans;   
    }

    bool dfs(char src, unordered_map<char, vector<char>>& graph, unordered_map<char, int>& visited,
        unordered_map<char, int>& inPath, string& ans
    ){
        visited[src] = 1;
        inPath[src] = 1;

        for(auto adj: graph[src]){
            if(inPath[adj]) return false;

            if(!visited[adj]){
                if(!dfs(adj, graph, visited, inPath, ans)) return false;
            }
        }

        inPath[src] = 0;
        ans.push_back(src);
        return true;
    }
};
