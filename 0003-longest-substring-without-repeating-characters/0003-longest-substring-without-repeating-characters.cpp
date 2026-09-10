class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*if(s.empty()) return 0;
        set<char> ss;int ans=1;
        /*for(int l=0;l<s.size();l++){
            ss.clear();
            if(ss.count(s[l])==0) ss.insert(s[l]) ;
            int r=l+1;
            while(r<s.size() && ss.count(s[r])==0){
                ss.insert(s[r]);
                r++;
            }
            ans=max(ans,r-l);
        }
        int l=0; int r=0;
        while(r<s.size()){
            if(ss.count(s[r])==0){
                ss.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            else{
                ss.erase(s[l]);
                l++;
            }
        }
        return ans;*/

        set<char> st;
        int l = 0, ans = 0;
        for(int r = 0; r < s.size(); r++) {
            while(st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};