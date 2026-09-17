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
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(); int ans=0;stack<int> s; vector<int> nextsmall(n,0); vector<int> presmall(n,0);

        nse(heights,s,nextsmall);
        while(!s.empty()) s.pop();
        pse(heights,s,presmall);

        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(nextsmall[i]+presmall[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(); int m=matrix[0].size(); int ans=0; vector<int> arr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') arr[j]++;
                else arr[j]=0;
            }
            ans=max(ans,largestRectangleArea(arr));
        }
        return ans;
    }
};