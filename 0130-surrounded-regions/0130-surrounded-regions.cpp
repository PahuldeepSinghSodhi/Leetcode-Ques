class Solution {

private:

    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &board,
             int drow[], int dcol[],
             int n, int m) {

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 &&
                board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, vis, board, drow, dcol, n, m);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // rows
        for (int j = 0; j < m; j++) {

            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, drow, dcol, n, m);
            }

            // CHANGED board[0][j] -> board[n-1][j]
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, drow, dcol, n, m);
            }
        }   // <-- Missing brace

        // columns
        for (int i = 0; i < n; i++) {

            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, drow, dcol, n, m);
            }

            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, drow, dcol, n, m);
            }
        }   // <-- Missing brace

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};