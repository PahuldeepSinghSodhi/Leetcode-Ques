# swim in rising water/submissions/2089785843

**Platform:** LeetCode  
**Date:** 2026-08-01  

## Solution

```
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
      dist[0][0] = grid[0][0];
      pq.push({grid[0][0],0,0});

      while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int time = curr[0];
        int row = curr[1];
        int col = curr[2];

        if( row == n-1 && col == n-1) return time;
        if(time > dist[row][col]) continue;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int k = 0 ; k < 4 ; k++){
            int newr = row + drow[k];
            int newc = col + dcol[k];
            if(newr >= 0 && newc >= 0 && newr < n && newc < n){
                int newTime = max(time,grid[newr][newc]);

                if( newTime < dist[newr][newc]){
                    dist[newr][newc] = newTime;
                    pq.push({newTime,newr,newc});
                }
            }
        }
      }
      return -1;
    }
};
```
