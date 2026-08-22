class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1); vector<int> cnt(n, 1); int maxi=0;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[i]>nums[pre]){
                    if (dp[pre] + 1 > dp[i]) {
                        dp[i] = dp[pre] + 1;
                        cnt[i] = cnt[pre];
                    }

                    else if (dp[pre] + 1 == dp[i]) {
                        cnt[i] += cnt[pre];
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
             if (dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};