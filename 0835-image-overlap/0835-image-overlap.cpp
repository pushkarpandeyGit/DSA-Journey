class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> v1; vector<pair<int,int>> v2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) v1.push_back({i,j});
                if(img2[i][j]==1) v2.push_back({i,j});
            }
        }
        map< pair<int,int>,int> m;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                int dx = v2[j].first-v1[i].first;
                int dy = v2[j].second-v1[i].second;
                m[{dx,dy}]++;
            }
        }
        int ans=0;
        for(auto & i:m){
            ans=max(i.second,ans);
        }
        return ans;
    }
};