class Solution {
public:
    void nse (vector<int> &nums,stack<int> & s,vector<int> &ans){
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty()) ans[i]=n-i;
            else ans[i]=s.top()-i;
            s.push(i);
        }
    }
    void pse (vector<int> &nums,stack<int> & s,vector<int>& ans){
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] > nums[i]){
                s.pop();
            }
            if(s.empty()) ans[i]=i+1;
           else ans[i]=i-s.top();
            s.push(i);
        }
    }
    void nge (vector<int> &nums,stack<int> & s,vector<int> &ans){
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                s.pop();
            }
            if(s.empty()) ans[i]=n-i;
            else ans[i]=s.top()-i;
            s.push(i);
        }
    }
    void pge (vector<int> &nums,stack<int> & s,vector<int> &ans){
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                s.pop();
            }
            if(s.empty()) ans[i]=i+1;
            else ans[i]=i-s.top();
            s.push(i);
        }
    }
    long long subarr_min(vector<int>& nums){
        int n=nums.size();
        vector<int> left(n,0); vector<int> right(n,0) ;stack<int> s;
        pse(nums,s,left);
        while(!s.empty()) s.pop();
        nse(nums,s,right);
        long long minsum=0;
        for(int i=0;i<n;i++){
            minsum+=(long long)nums[i]*left[i]*right[i];
        }
        return minsum;
    }
    long long subarr_max(vector<int> &nums){
        int n=nums.size();
        vector<int> left(n,0) ; vector<int> right(n,0) ;stack<int> s;
        pge(nums,s,left);
        while(!s.empty()) s.pop();
        nge(nums,s,right);
        long long maxsum=0;
        for(int i=0;i<n;i++){
            maxsum+=(long long)nums[i]*left[i]*right[i];
        }
        return maxsum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long max_subarr_sum=subarr_max(nums);
        long long min_subarr_sum=subarr_min(nums);
        return max_subarr_sum-min_subarr_sum;
    }
};