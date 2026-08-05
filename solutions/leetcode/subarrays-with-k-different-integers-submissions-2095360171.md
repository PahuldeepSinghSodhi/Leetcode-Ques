# subarrays with k different integers/submissions/2095360171

**Platform:** LeetCode  
**Date:** 2026-08-05  

## Solution

```
class Solution {

    private: 
     int count(vector<int>& nums, int k){

        if(k < 0) return 0; 
        int cnt = 0,l=0,r=0;
        unordered_map<int,int> mpp;

        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k) - count(nums,k-1);
        
    }
};
```
