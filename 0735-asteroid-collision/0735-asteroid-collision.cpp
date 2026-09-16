class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) s.push(asteroids[i]);
            else{
                while(!s.empty() && s.top()>0 &&abs(asteroids[i])>s.top()){
                    s.pop();
                }
                if(!s.empty() && abs(asteroids[i])==s.top()) s.pop();
                else if(s.empty()||s.top()<0){
                    s.push(asteroids[i]);
                }
                
            }
        }
        vector<int> ans(s.size());
        for(int i=s.size()-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};