class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone: stones){
            pq.push(stone);
        }

        while(pq.size() >= 2){
            int stone1 = pq.top();
            pq.pop();

            int stone2 = pq.top();
            pq.pop();

            if(stone1 == stone2) continue;
            else pq.push(abs(stone1-stone2));
        }

        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
