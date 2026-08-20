# Here is an Approach :-)

**Platform:** LeetCode  
**Date:** 2026-08-20  

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
        vector<int> prev(cols,0);

        for(int i = 0 ; i < rows ; i++){
            vector<int> curr(cols,0);
            for(int j = 0 ; j < cols ; j++){
                if(i == 0 && j == 0 ) curr[j] = grid[i][j];
                else{
                    //req prevcious rows
                    int up = grid[i][j];
                    if(i>0) up+=prev[j];
                    else up+=1e9;
                    //req curr row
                    int left = grid[i][j];
                    if(j>0) left += curr[j-1];
                    else left+=1e9;

                    curr[j] = min(up,left);
                }
         
            }
            prev = curr;
        }
        return prev[cols-1];
    }
};
```
