# max consecutive ones iii/submissions/2092373127

**Platform:** LeetCode  
**Date:** 2026-08-03  

## Solution

```
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, l = 0, r = 0,zeros=0;

        while(r < nums.size()){
            if(nums[r]==0)zeros++;
            while(zeros > k){
                if(nums[l]==0)zeros--;
                l++;
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            r++;
        }
        return maxlen;
    }
};
```
