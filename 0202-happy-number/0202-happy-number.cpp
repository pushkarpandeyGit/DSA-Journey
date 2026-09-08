class Solution {
public:
    int digitsquaresum(int x){
        int sum=0;
        while(x>0){
            int d=x%10;
            sum+=d*d;
            x=x/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int>s;
        while(n!=1){
            if(s.count(n)) return false;
            s.insert(n);
            n=digitsquaresum(n);
        }
        return true;
    }
};