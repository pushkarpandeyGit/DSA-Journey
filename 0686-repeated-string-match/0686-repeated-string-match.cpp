bool isSubstring(string s, string p) {
    int n=s.size(), m=p.size();
    
    if(m>n) return false;

    long long base=31, mod=1e9+7;
    long long ph=0, wh=0, power=1;

    for(int i=0;i<m;i++){
        ph=(ph*base+p[i])%mod;
        wh=(wh*base+s[i])%mod;

        if(i<m-1)
            power=(power*base)%mod;
    }

    for(int i=0;i<=n-m;i++){
        if(ph==wh){
            bool same=true;

            for(int j=0;j<m;j++){
                if(s[i+j]!=p[j]){
                    same=false;
                    break;
                }
            }

            if(same) return true;
        }

        if(i<n-m){
            wh=(wh-s[i]*power%mod+mod)%mod;
            wh=(wh*base+s[i+m])%mod;
        }
    }

    return false;
}
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp=a;
        int count=1;

        while(a.size()<b.size()){
            a+=temp;
            count++;
        }

        if(isSubstring(a,b)) return count;

        a+=temp;

        if(isSubstring(a,b)) return count+1;

        return -1;
    }
};