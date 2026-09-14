class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0);
        if(nums[0]==0)pre[0]=-1;
        else pre[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]==0) pre[i]=pre[i-1]+(-1);
            else pre[i]=pre[i-1]+(1);
        }
        unordered_map<int,int> m;int ans=0; //subarr with sum 0 que
        for(int i=0;i<n;i++){
            if(pre[i]==0) ans=max(ans,i+1);
            if(m.count(pre[i]-0)) ans=max(ans,i-m[pre[i]-0]);
            if(!m.count(pre[i])) m[pre[i]]=i;
        }
        return ans;
    }
};