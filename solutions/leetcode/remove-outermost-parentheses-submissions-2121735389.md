# remove outermost parentheses/submissions/2121735389

**Platform:** LeetCode  
**Date:** 2026-08-27  

## Solution

```
class Solution {
public:
    string removeOuterParentheses(string s) {

       string ans = "";
       int cnt = 0;

       for(char ch : s){
        if(ch == '(') {
            if(cnt > 0) ans += ch;
            cnt++;
        }
        if(ch == ')'){
            cnt--;
            if(cnt > 0) ans+= ch;
        }
       }

       return ans;
    }
};
```
