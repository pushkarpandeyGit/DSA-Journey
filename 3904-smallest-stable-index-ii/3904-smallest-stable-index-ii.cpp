class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> v(n,{INT_MAX,-1});
        v[0].second=nums[0];
        for(int i=1;i<n;i++){
            v[i].second=max(v[i-1].second,nums[i]);
        }
        v[n-1].first=nums[n-1];
        for(int i=n-2;i>=0;i--){
            v[i].first=min(v[i+1].first,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(v[i].second-v[i].first<=k){
                return i;
            }
        }
        return -1;
    }
};