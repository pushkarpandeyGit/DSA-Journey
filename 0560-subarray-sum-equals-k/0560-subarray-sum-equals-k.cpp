class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        unordered_map<int,int> m;
        m[0] = 1; int c = 0;
        for(int i = 0; i < n; i++) {
            if(m.count(pre[i] - k)) c+=m[pre[i] - k];
            m[pre[i]]++;
        }

        return c;
    }
};