class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Max Heap: {minimum safeness till now, row, col}
        priority_queue<vector<int>> pq;
        pq.push({dist[0][0], 0, 0});

        vector<vector<int>> best(n, vector<int>(n, -1));
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == n - 1 && c == n - 1)
                return safe;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newSafe = min(safe, dist[nr][nc]);

                    if (newSafe > best[nr][nc]) {
                        best[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};