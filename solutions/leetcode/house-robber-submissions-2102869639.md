# house robber/submissions/2102869639

**Platform:** LeetCode  
**Date:** 2026-08-11  

## Solution

```
class Solution {
public:
    int rob(vector<int>& nums) {

        int n  = nums.size();
        int prev1 = nums[0],prev2 = 0;
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];

        for(int i = 1 ; i < n ; i ++){

            int take = nums[i]; if(i > 1) take += dp[i-2];
            int nottake = 0 + dp[i-1];
            dp[i] = max(take,nottake);
        }

        return dp[n-1];
    }
};
```
