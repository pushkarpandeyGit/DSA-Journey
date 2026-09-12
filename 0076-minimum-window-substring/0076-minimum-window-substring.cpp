class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int l=0; unordered_map<char,int> need, m; int c=0; string ans="";
        for(int i=0;i<t.size();i++){
            need[t[i]]++;
        }
        int start = 0, len = INT_MAX;
        for(int r=0;r<s.size();r++){
            if(need.count(s[r])){
                m[s[r]]++;
                if(m[s[r]] <= need[s[r]]) c++;
            }
            while(c==t.size()){
                if(r-l+1 < len){
                    len = r-l+1;
                    start = l;
                }
                if(need.count(s[l])){
                    if(m[s[l]] <= need[s[l]]) c--;
                    m[s[l]]--;
                }
                l++;
            }
        }
        if(len==INT_MAX) return "";
        return s.substr(start,len);
    }
};