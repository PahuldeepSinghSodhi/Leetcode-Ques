# Longest Substring With At Most K Distinct Characters

**Platform:** TakeYouForward  
**Date:** 2026-08-05  

## Solution

```
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int maxlen=0;unordered_map<char,int> mpp; int n = s.size();
        for(int i = 0 ; i < n ; i++){
            mpp.clear();
            for(int j = i ; j < n ; j++){
                mpp[s[j]]++;
                if(mpp.size() <= k){
                    maxlen = max(maxlen,j-i+1);
                }
                else break;
            }
        }
        return maxlen;
    }
};
```
