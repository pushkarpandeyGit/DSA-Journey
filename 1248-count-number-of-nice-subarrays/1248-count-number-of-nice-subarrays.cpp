class Solution {
public:
    int help(vector<int>& nums, int k){
        vector<int> v;
        int c=0;int l=0;int ptr=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2==1) v.push_back(r);
            while(v.size() - ptr > k){
                l = v[ptr] + 1;
                ptr++;
            }
            c+=r-l+1;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};