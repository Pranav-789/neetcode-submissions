class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string s = "";
        
        for(auto str: strs){
            for(auto ch: str){
                if(ch == ',' || ch == '/') s += '/';
                s += ch;
            }
            s += ',';
        }

        return s;
    }

    vector<string> decode(string s) {
        if(s.size() == 0) return {};
        vector<string> ans;
        int i = 0;
        string c = "";
        while(i < s.length()){
            if(s[i] == '/'){
                c += s[i+1];
                i += 2;
            }
            else if(s[i] == ','){
                ans.push_back(c);
                c = "";
                i+=1;
            }else{
                c += s[i];
                i += 1;
            }
        }
        return ans;
    }
};

