class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        unordered_map<int,int> m; m[0]=1;  int c=0;
        for(int i=0;i<n;i++){
            int rem=pre[i]%k;
            if(rem<0) rem+=k;
            if(m.count(rem)) c+=m[rem];
            m[rem]++;
        }
        return c;
    }
};