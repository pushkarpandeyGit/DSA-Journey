class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        int odd=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==1){
                odd=nums1[i];break;
            } 
        }
        if(odd==0) return true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                if(nums1[i]-odd<1) return false;
            }
        }
        return true;
    }
};