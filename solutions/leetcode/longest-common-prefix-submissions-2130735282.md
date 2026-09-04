# longest common prefix/submissions/2130735282

**Platform:** LeetCode  
**Date:** 2026-09-04  

## Solution

```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i = 1 ; i < strs.size() ; i++){
            while(strs[i].find(prefix) != 0){
                prefix.pop_back();
            }

        }
        return prefix;
    }
};
```
