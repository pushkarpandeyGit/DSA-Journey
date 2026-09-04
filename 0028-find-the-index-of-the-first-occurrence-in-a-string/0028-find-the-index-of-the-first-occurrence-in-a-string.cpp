/*### KMP — Rev Points

* Build the **LPS array on `needle`** first.
* `lps[i]` = longest proper prefix that is also a suffix of `needle[0..i]`.
* During LPS mismatch with `pre > 0`, set `pre = lps[pre-1]`.
* During LPS mismatch with `pre == 0`, set `lps[suf] = 0` and move `suf`.
* During search, `first` points to `haystack` and `sec` points to `needle`.
* On match, increment both `first` and `sec`.
* On mismatch with `sec > 0`, jump `sec = lps[sec-1]` without moving `first`.
* On mismatch with `sec == 0`, move `first++`.
* When `sec == n`, the needle is found at `first-sec`.
* If `first == m` before finding the pattern, return `-1`.
* **Memory:** LPS is for the pattern; KMP uses it to avoid moving the text pointer backward.
* **Complexity:** `O(m+n)` time and `O(n)` space.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        vector<int> lps(n,0);
        int pre=0;int suf=1;
        while(suf<n){
            if(needle[pre]==needle[suf]){
                lps[suf]=pre+1;
                pre++;suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }

        int first=0;int sec=0;
        while(first<m){
            if(haystack[first]==needle[sec]){
                first++;sec++;
                if(sec==n){
                    return first-sec;
                }
            }
            else{
                if(sec==0){
                    first++;
                }
                else{
                    sec=lps[sec-1];
                }
            }
        }
        return -1;
    }
};