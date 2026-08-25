class Solution {
public:
    int help(int i,int k,vector<int>& arr,vector<int> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0;int ans=0;
        for(int idx=i;idx<min(i+k,(int)arr.size());idx++){
            maxi=max(maxi,arr[idx]);
            int cost=maxi*(idx-i+1)+help(idx+1,k,arr,dp);
            ans=max(ans,cost);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return help(0,k,arr,dp);
    }
};