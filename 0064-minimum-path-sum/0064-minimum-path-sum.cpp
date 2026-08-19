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

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(i == 0 && j == 0 ) dp[i][j] = grid[i][j];
                else{
                    
                    int up = grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;

                    int left = grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left+=1e9;

                    dp[i][j] = min(up,left);
                }

         
            }
        }
        return dp[rows-1][cols-1];
    }
};