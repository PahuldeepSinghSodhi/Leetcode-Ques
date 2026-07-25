# minimum number of operations to satisfy conditions/submissions/2080964975

**Platform:** LeetCode  
**Date:** 2026-07-25  

## Solution

```
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // cost[col][digit] = operations needed to make entire column = digit
        vector<vector<int>> cost(n, vector<int>(10, 0));

        for (int col = 0; col < n; col++) {
            vector<int> freq(10, 0);

            for (int row = 0; row < m; row++)
                freq[grid[row][col]]++;

            for (int d = 0; d <= 9; d++)
                cost[col][d] = m - freq[d];
        }

        vector<vector<int>> dp(n, vector<int>(10, INT_MAX));

        // First column
        for (int d = 0; d <= 9; d++)
            dp[0][d] = cost[0][d];

        // Remaining columns
        for (int col = 1; col < n; col++) {
            for (int cur = 0; cur <= 9; cur++) {
                for (int prev = 0; prev <= 9; prev++) {
                    if (cur == prev) continue;
                    dp[col][cur] = min(dp[col][cur],
                                       dp[col - 1][prev] + cost[col][cur]);
                }
            }
        }

        int ans = INT_MAX;

        for (int d = 0; d <= 9; d++)
            ans = min(ans, dp[n - 1][d]);

        return ans;
    }
};
```
