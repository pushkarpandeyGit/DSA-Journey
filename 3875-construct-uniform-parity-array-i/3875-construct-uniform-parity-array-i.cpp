class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1){
                odd=nums1[i];
                break;
            }
        }
        if(odd==INT_MAX) return true;
        return true;
    }
};