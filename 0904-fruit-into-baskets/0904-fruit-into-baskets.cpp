class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;int l=0;unordered_map<int,int >m;
        for(int r=0;r<fruits.size();r++){
            m[fruits[r]]++;
            while(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0) m.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};