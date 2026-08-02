# max consecutive ones iii/submissions/2091455722

**Platform:** LeetCode  
**Date:** 2026-08-02  

## Solution

```
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeros = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0)
                zeros++;

            while (zeros > k) {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```
