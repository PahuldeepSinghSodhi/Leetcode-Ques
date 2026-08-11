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

        for(int i = 1 ; i < n ; i ++){

            int take = nums[i]; if(i > 1) take += prev2;
            int nottake = 0 + prev1;
            int curr = max(take,nottake);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
```
