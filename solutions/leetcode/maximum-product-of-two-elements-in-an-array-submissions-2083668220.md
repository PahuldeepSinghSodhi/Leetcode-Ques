# maximum product of two elements in an array/submissions/2083668220

**Platform:** LeetCode  
**Date:** 2026-07-27  

## Solution

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int first = 0;
        int second = 0;

        for(int x : nums){

            if(x > first){
                second = first;
                first = x;
            }
            else if(x > second){
                second = x;
            }
        }

        return (first - 1) * (second - 1);
    }
};
```
