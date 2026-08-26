class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;int c=0;int bestlen=INT_MAX;string ans="";
        for(int r=0;r<s.size();r++){
            if(s[r]=='1') c++;
            while(c>k){
                if(s[l]=='1'){
                    c--;
                    l++;
                }
                else l++;
            }
            if(c==k){
                while(l < r && s[l] == '0') l++;
                int len = r - l + 1;
                if(len < bestlen){
                    bestlen = len;
                    ans = s.substr(l, len);
                }
                else if(len == bestlen){
                    string cur = s.substr(l, len);
                    if(cur < ans)
                        ans = cur;
                }
            }
        }
        return ans;
    }
};