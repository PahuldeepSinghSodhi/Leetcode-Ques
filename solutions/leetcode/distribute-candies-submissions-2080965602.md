# distribute candies/submissions/2080965602

**Platform:** LeetCode  
**Date:** 2026-07-25  

## Solution

```
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_set<int> st;

        for (int x : candyType)
            st.insert(x);

        return min((int)st.size(), (int)candyType.size() / 2);
    }
};
```
