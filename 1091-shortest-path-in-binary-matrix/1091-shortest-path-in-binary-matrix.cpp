class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;   // edge case: start == end

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        q.push({1, {0,0}});

        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0 ; i < 8 ; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] == 1e9){
                    dist[nr][nc] = d + 1;
                    if(nr == n-1 && nc == n-1) return dist[nr][nc];
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
    }
};