class Solution {
public:
    int help(int i,int j,string s, string t,vector<vector<int>> & dp ){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=help(i+1,j+1,s,t,dp)+help(i+1,j,s,t,dp);
        else return dp[i][j]=help(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int ss=s.size(); int ts=t.size();
        vector<vector<int>> dp(ss+1,vector<int>(ts+1,-1));
        return help(0,0,s,t,dp);
    }
};