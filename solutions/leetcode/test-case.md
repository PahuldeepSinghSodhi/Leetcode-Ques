# test case :-

**Platform:** LeetCode  
**Date:** 2026-08-11  

## Solution

```
class Solution {
public:

    // House Robber I
    int housevalue(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {

            int take = nums[i];

            if(i > 1)
                take += prev2;

            int nottake = prev1;

            int curr = max(take, nottake);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // House Robber II
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++) {

            // Exclude first house
            if(i != 0)
                temp1.push_back(nums[i]);

            // Exclude last house
            if(i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(housevalue(temp1), housevalue(temp2));
    }
};
```
