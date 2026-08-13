# unique paths ii/description

**Platform:** LeetCode  
**Date:** 2026-08-13  

## Solution

```
class Solution {

    private: 
    int f(int i, int j, vector<vector<int>>& dp,vector<vector<int>>& obs ){

        if(i < 0 || j < 0) return 0;

        if(obs[i][j] == 1) return 0;

        if(i == 0 && j == 0) return dp[i][j] = 1;
        
        else{
        if(dp[i][j] != -1) return dp[i][j];
        int up = 0, left = 0;
        up = f(i-1,j,dp,obs);
        left = f(i,j-1,dp,obs);
        return dp[i][j] = up + left;
        }

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(n-1,m-1,dp,obstacleGrid);
        
    }
};
```
