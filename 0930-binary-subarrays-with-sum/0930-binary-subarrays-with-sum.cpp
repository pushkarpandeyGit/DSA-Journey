class Solution {
public:
    int help(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l=0;int c=0;int s=0;
        for(int r=0;r<nums.size();r++){
            s+=nums[r];
            while(s>goal){
                s-=nums[l];
                l++;
            }
            c+=r-l+1;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums,goal)-help(nums,goal-1);
    }
};