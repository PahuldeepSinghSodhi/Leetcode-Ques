# Here is an Approach :-)

**Platform:** LeetCode  
**Date:** 2026-08-19  

## Solution

```
class Solution {
private:
int s(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
    int ans=0;int left=0;
    if(i == 0 && j ==0) return dp[i][j] = grid[i][j];
    if(i<0 || j<0) return  1e9;
    else {
        if(dp[i][j] != -1) return dp[i][j];
        ans = grid[i][j] + min(s(i-1,j,grid,dp),s(i,j-1,grid,dp));
        
    }
    return dp[i][j] = ans;
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        return s(rows-1,cols-1,grid,dp);
    }
};
```
