class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0 , ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(bal<0){
                    ans+=abs(bal);
                    bal=0;
                }
                bal++;
            }
            else{
                bal--;
            }
        }
        return ans+abs(bal);
    }
};