class Solution {
public:
    bool ispalin(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            j--;i++;
        }
        return true;
    }
    int help(int i,string s,vector<int> & dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispalin(i,j,s)){
                int cost=1+help(j+1,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return help(0,s,dp)-1;
    }
};