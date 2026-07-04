class MinStack {
    vector<int> v;
    vector<int> mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        if(mini.size() == 0) mini.push_back(val);
        else{
            int minil = min(mini.back(), val);
            mini.push_back(minil);
        }
    }
    
    void pop() {
        v.pop_back();
        mini.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return mini.back();
    }
};
