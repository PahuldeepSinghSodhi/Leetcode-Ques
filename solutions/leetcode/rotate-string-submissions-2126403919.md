# rotate string/submissions/2126403919

**Platform:** LeetCode  
**Date:** 2026-08-31  

## Solution

```
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) return false;

        return (s+s).find(goal) != string::npos;
        
    }
};
```
