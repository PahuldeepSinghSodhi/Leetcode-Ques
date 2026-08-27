# rotate string/submissions/2121814619

**Platform:** LeetCode  
**Date:** 2026-08-27  

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
