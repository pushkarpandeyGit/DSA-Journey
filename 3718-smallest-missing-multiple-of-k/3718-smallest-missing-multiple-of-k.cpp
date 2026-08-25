class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        for(int i=k; ;i=i+k){
            if(s.count(i)==0) return i;
        }
        return -1;
    }
};