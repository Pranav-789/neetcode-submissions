class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(int i = 0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto adj: graph[node]){
                int newd = dis + adj.second;

                if(newd < dist[adj.first]){
                    dist[adj.first] = newd;
                    pq.push({newd, adj.first});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
