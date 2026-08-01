# Maximum Points You Can Obtain from Cards

**Platform:** TakeYouForward  
**Date:** 2026-08-01  

## Solution

```
class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        //your code goes here
        int n = cardScore.size();
        int l = k-1;
        int r = n-1;
        int sum = 0;
        int maxsum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += cardScore[i];
        }
        maxsum = sum;

        while(r > n-k-1){
            sum -= cardScore[l];
            l--;
            sum += cardScore[r];
            r--;

            maxsum = max(sum,maxsum);
        }
        return maxsum;
    }
};
```
