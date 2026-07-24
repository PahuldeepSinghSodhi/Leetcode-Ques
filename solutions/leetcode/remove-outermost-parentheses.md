# remove outermost parentheses

**Platform:** LeetCode  
**Date:** 2026-07-24  

## Solution

```
class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int cnt = 0;

        for (char ch : s) {

            if (ch == '(') {
                if (cnt > 0)
                    ans += ch;
                cnt++;
            }
            else {
                cnt--;
                if (cnt > 0)
                    ans += ch;
            }
        }

        return ans;
    }
};
```
