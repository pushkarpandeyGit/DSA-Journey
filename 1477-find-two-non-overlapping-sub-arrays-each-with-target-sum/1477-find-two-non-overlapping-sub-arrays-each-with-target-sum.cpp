class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l=0; int n=arr.size(); vector<int> dp(n+1,INT_MAX); int ans=INT_MAX; int s=0;
        dp[0]=INT_MAX;

        for(int r=0;r<n;r++){
            s+=arr[r];
            while(s>target){
                s-=arr[l];
                l++;
            }
            dp[r+1]=dp[r];
            if(s==target){
                if(l>0 && dp[l]!=INT_MAX) ans=min(ans,dp[l]+r-l+1);  //dp[l] + current length = two non-overlapping subarrays
                dp[r+1]=min(dp[r],r-l+1);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};