# test case :-

**Platform:** LeetCode  
**Date:** 2026-08-11  

## Solution

```
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        // Case 1: Exclude last house
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n - 1; i++) {

            int take = nums[i] + prev2;
            int nottake = prev1;

            int curr = max(take, nottake);

            prev2 = prev1;
            prev1 = curr;
        }

        int finalans = prev1;


        // Case 2: Exclude first house
        prev1 = 0;
        prev2 = 0;

        for(int i = 1; i < n; i++) {

            int take = nums[i] + prev2;
            int nottake = prev1;

            int curr = max(take, nottake);

            prev2 = prev1;
            prev1 = curr;
        }

        finalans = max(finalans, prev1);

        return finalans;
    }
};
```
