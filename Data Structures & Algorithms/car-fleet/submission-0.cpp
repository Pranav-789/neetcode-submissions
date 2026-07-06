class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
                vector<pair<int, double>> v;
                        
                int n = position.size();
                                        
                for(int i = 0; i < n; i++){
                    v.push_back({position[i], (target-position[i])/(double)speed[i]});
                }
                                                                            
                sort(v.begin(), v.end());
                                                                                            
                stack<pair<int, double>> st;
                st.push(v[n-1]);
                                                                                                                    
                for(int i = n-2; i >= 0; i--){
                    if(st.top().second < v[i].second) st.push(v[i]);
                }
                return st.size();
            }
}; 