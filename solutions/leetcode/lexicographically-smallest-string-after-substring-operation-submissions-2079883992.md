# lexicographically smallest string after substring operation/submissions/2079883992

**Platform:** LeetCode  
**Date:** 2026-07-24  

## Solution

```
class Solution {
public:
    string smallestString(string s) {

        int n = s.size();
        int i = 0;

        // Skip leading 'a's
        while (i < n && s[i] == 'a')
            i++;

        // If all characters are 'a'
        if (i == n) {
            s[n - 1] = 'z';
            return s;
        }

        // Decrease consecutive non-'a' characters by 1
        while (i < n && s[i] != 'a') {
            s[i]--;
            i++;
        }

        return s;
    }
};
```
