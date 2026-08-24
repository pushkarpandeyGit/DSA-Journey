class Solution {
public:
    bool help(int & i,string &s){
        if(s[i] == 't') {
            i++;
            return true;
        }
        if(s[i] == 'f') {
            i++;
            return false;
        }
        char curr=s[i];
        i+=2;
        bool ans = (curr == '&');
        while(s[i]!=')'){
            if(s[i]==','){
                i++;
                continue;
            }
            bool val=help(i,s);
            if(curr=='&') ans=ans && val;
            else if(curr=='|') ans= ans || val;
            else if(curr=='!') ans= !(val);
        }
        i++;
        return ans;
    }
    bool parseBoolExpr(string expression) {
        int i=0;
        return help(i,expression);
    }
};