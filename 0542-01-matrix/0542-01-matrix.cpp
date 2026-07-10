class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                dist[row][col] = steps;

                for (int j = 0; j < 4; j++) {

                    int nrow = row + delRow[j];
                    int ncol = col + delCol[j];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol]) {

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }

            steps++;
        }

        return dist;
    }
};