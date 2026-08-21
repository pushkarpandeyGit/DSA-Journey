class Solution {
public:
    static bool comp(string s1, string s2) {
        return s1.size() < s2.size();
    }
    bool compare(string i,string pre){
        if(i.size() != pre.size() + 1) return false;
        int ptr1=0, ptr2=0;
        while(ptr1<i.size()){
            if(i[ptr1]==pre[ptr2]){
                ptr1++;ptr2++;
            }
            else ptr1++;
        }
        return ptr2 == pre.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        if(n==1) return 1;
        vector<int> dp(n,1); int maxi=0;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(compare(words[i],words[pre])==true && dp[pre]+1>=dp[i]){
                    dp[i]=1+dp[pre];
                }
                maxi=max(maxi,dp[i]);
            }
        }
        return maxi;
    }
};