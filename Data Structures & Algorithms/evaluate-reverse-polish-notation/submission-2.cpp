class Solution {
    int numToken(string token){
        if(token[0] == '-'){
            int sign = -1;
            int ans = 0;
            for(int i = 1; i < token.size(); i++){
                ans = ans * 10 + (token[i]-'0');
            }
            return ans*sign;
        }else{
            int ans = 0;
            for(int i = 0; i < token.size(); i++){
                ans = ans * 10 + (token[i]-'0');
            }
            return ans;
        }
    }

    bool isOp(string token){
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }

    int operate(int n1, int n2, string op){
        if(op == "+"){
            return n1 + n2;
        } else if(op == "-"){
            return n2 - n1;
        } else if(op == "*"){
            return n1*n2;
        } else{
            return n2/n1;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            if(isOp(tokens[i])){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(operate(num1, num2, tokens[i]));
            }
            else{
                st.push(numToken(tokens[i]));
            }
        }
        return st.top();
    }
};
