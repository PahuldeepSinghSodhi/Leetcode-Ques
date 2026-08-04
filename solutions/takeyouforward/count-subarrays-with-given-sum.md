# Count subarrays with given sum

**Platform:** TakeYouForward  
**Date:** 2026-08-04  

## Solution

```
class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int n = nums.size(),cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i ; j < n ; j ++){
                int sum = 0;
                for(int l = i ; l <=j ; l++ ){
                    sum += nums[l];
                }
                if(sum == k){
                    cnt++;
                }
                else continue;
            }
        }
        return cnt;
    }
};
```
