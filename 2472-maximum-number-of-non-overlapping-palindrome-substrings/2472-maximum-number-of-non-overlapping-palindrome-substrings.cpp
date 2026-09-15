class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();

        vector<vector<bool>> pal(n,vector<bool>(n,false));

        // 2D DP for palindrome
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=1 || pal[i+1][j-1]))
                    pal[i][j]=true;
            }
        }

        // 1D DP
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1];

            for(int j=i;j<n;j++){
                if(j-i+1>=k && pal[i][j]){
                    dp[i]=max(dp[i],1+dp[j+1]);
                }
            }
        }

        return dp[0];
    }
};