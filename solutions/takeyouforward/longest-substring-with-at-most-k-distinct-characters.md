# Longest Substring With At Most K Distinct Characters

**Platform:** TakeYouForward  
**Date:** 2026-08-05  

## Solution

```
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int maxlen=0,l=0,r=0;
        unordered_map<char,int> mpp;

        while(r < s.size()){
            mpp[s[r]]++;

            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }

            if(mpp.size() <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
```
