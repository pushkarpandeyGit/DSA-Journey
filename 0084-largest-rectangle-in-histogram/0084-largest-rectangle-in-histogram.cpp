class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;stack<int> s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                int h=heights[s.top()];s.pop();
                int width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                int area=h*width;
                ans=max(ans,area);
            }
            s.push(i);
        }
        while(!s.empty()){
            int h=heights[s.top()]; s.pop();
            int width;
            if(s.empty())
                width=heights.size();
            else
                width=heights.size()-s.top()-1;
            int area=h*width;
            ans=max(ans,area);
        }
        return ans;
    }
};