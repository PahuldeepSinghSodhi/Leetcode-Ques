# longest repeating character replacement/submissions/2092697801

**Platform:** LeetCode  
**Date:** 2026-08-03  

## Solution

```
class Solution {
public:
    int characterReplacement(string s, int k) {

       int l = 0, r = 0, maxlen = 0, maxfreq = 0;
       int hash[26] = {0};
       int slen = s.size();
       while(r < slen){
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq,  hash[s[r] - 'A']);

        while((r-l+1) - maxfreq > k){
            hash[s[l] - 'A']--; maxfreq = 0;
            for(int i = 0 ; i < 25 ; i++){
                maxfreq = max(maxfreq,hash[i]);
            }
            l++;
        }

        if((r-l+1) - maxfreq <= k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
       }
       return maxlen;
    }
};
```
