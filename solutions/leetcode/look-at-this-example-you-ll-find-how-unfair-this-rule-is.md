# Look at this example. You'll find how unfair this rule is.

**Platform:** LeetCode  
**Date:** 2026-07-25  

## Solution

```
class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> candy(n, 1);

        // Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        }

        // Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candy[i] = max(candy[i], candy[i + 1] + 1);
        }

        int ans = 0;

        for (int x : candy)
            ans += x;

        return ans;
    }
};
```
