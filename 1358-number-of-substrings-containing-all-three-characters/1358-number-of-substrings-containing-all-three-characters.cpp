class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m; int l=0;int c=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m.size()==3){
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            c+=l;
        }
        return c;
    }
};