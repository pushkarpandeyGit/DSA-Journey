class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;int fast=0;int n=nums.size();
        while(slow!=fast || slow == 0){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        int p1=0;
        while(p1!=slow){
            p1=nums[p1]; slow=nums[slow];
        }
        return p1;
    }
};