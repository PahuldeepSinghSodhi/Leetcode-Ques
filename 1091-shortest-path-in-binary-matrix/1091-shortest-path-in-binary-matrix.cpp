class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){ // we cant even start or we camt even end 
            return -1;
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        int drow[] = {-1,-1,0,1,1,1,0,-1}; // 8 ways check
        int dcol[] = {0,1,1,1,0,-1,-1,-1};
        queue <pair<pair<int,int>,int>> q;
        q.push({{0,0},1}); //starting cell and first step alr taken to rwach there
        vis[0][0] = 1;

        while(!q.empty()){
            int dist = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();

            if(row == n-1 && col == n-1){ // checking if reached target cell
                return dist;
            }

            for(int i = 0 ; i < 8 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i]; // traversing nerighbours
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){ //putting vis cells as neighbours in queue
                vis[nrow][ncol] = 1;    
                q.push({{nrow,ncol},dist+1});
                }
            }
        }
       
        return -1;
    }
};