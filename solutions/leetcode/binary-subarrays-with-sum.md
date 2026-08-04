# binary subarrays with sum

**Platform:** LeetCode  
**Date:** 2026-08-04  

## Solution

```
class Solution {
    private :
    int count(vector<int>& nums, int goal) {
        int l = 0 , r = 0 ,sum = 0, cnt = 0;
         if(goal < 0) return 0;
        while( r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       
        return count(nums,goal) - count(nums,goal-1);
    }
};
```
