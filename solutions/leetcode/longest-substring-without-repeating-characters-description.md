# longest substring without repeating characters/description

**Platform:** LeetCode  
**Date:** 2026-08-01  

## Solution

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0,r = 0,n=s.size(),len,maxlen =0;
        unordered_map<char,int> mpp;

        while(r<n){
            if(mpp.find(s[r]) != mpp.end()){
                if(mpp[s[r]] >= l){
                    l = mpp[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxlen = max(len, maxlen);

            mpp[s[r]] = r;
            r++;

        }
        return maxlen;
    }
};
```
