class Solution {
public:
    vector<string> help(int n){
        if(n==1) return {"()"};
        vector<string> pre = help(n-1);
        set<string> s;
        for(string x : pre){
            for(int i=0;i<=x.size();i++){
                string temp = x.substr(0,i) + "()" + x.substr(i);
                s.insert(temp);
            }
        }
        return vector<string>(s.begin(),s.end());
    }
    vector<string> generateParenthesis(int n) {
        return help(n);
    }
};