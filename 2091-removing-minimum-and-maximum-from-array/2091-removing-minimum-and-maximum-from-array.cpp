class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxind=0;int minind=0; int maxi=INT_MIN;int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxi){
                maxi=nums[i];
                maxind=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minind=i;
            }
        }
        int n=nums.size();
        if(minind>maxind)
            swap(minind,maxind);
        int ans=INT_MAX;
        // Both from front
        ans=min(ans,maxind+1);
        // Both from back
        ans=min(ans,n-minind);
        // Minimum from front, maximum from back
        ans=min(ans,minind+1+n-maxind);

        return ans;
    }
};