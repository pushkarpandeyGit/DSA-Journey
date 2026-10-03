class Solution {
public:
    int upper(vector<int>& nums, int target){
        int  l=0;int r=nums.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
         return l;
    }
    int lower(vector<int>& nums, int target){
        int  l=0;int r=nums.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
         return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lower(nums,target);
        int last=upper(nums,target)-1;
         if(first==nums.size() || nums[first]!=target)
            return {-1,-1};
        return {first,last};
    }
};