class Solution {
public:
    string countAndSay(int n) {
        string ans="";
        for(int i=1;i<=n;i++){
            if(i==1) ans="1";
            else{
                int j=1;int occ=1;string temp="";
                while(j<=ans.size()){
                    if(j<ans.size() && ans[j]==ans[j-1]) occ++;
                    else{
                        temp += to_string(occ) + ans[j-1];
                        occ=1;
                    }
                    j++;
                }
                ans=temp;
            }
        }
        return ans;
    }
};