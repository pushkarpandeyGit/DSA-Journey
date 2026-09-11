class Solution {
public:
    int help(vector<int>& nums,int k){
        unordered_map<int,int> m;  int l=0;; int c=0;
        for(int r=0;r<nums.size();r++){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            c+=r-l+1;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};