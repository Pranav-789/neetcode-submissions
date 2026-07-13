class KthLargest {
    int cap;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->cap = k;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > cap) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > cap) pq.pop();
        return pq.top();
    }
};

        