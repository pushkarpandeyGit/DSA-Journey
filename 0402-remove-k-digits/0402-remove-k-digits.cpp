class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s; int c=0;
        for(int i=0;i<num.size();i++){
            if(s.empty() || num[i]-'0' > s.top()){
                s.push(num[i]-'0');
            }
            else{
                while(!s.empty() && c<k && num[i]-'0'<s.top()){
                    s.pop();
                    c++;
                }
                s.push(num[i]-'0');
            }
        }
        while(!s.empty() && c<k){
            s.pop();
            c++;
        }
        string ans="";
        while(!s.empty()){
            ans += char(s.top()+'0');
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        ans=ans.substr(i);
        if(ans=="")return "0";
        return ans;
    }
};