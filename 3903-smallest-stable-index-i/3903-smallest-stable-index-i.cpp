class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxarr(n,-1); vector<int> minarr(n,INT_MAX);
        maxarr[0]=nums[0];minarr[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            maxarr[i]=max(maxarr[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            minarr[i]=min(minarr[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(maxarr[i]-minarr[i]<=k) return i;
        }
        return -1;
    }
};