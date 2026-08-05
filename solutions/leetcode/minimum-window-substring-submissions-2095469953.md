# minimum window substring/submissions/2095469953

**Platform:** LeetCode  
**Date:** 2026-08-05  

## Solution

```
class Solution {
public:
    string minWindow(string s, string t) {
        int minlen=INT_MAX,sIndex=-1,cnt=0,r=0,l=0,n=s.size(),m=t.size();
        int hash[256] = {0};

        for(int i = 0 ; i < m ; i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(sIndex == -1 ) return "";
        return s.substr(sIndex,minlen);
        
    }
};
```
