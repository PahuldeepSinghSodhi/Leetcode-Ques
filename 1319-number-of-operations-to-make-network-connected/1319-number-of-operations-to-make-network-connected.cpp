class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        vector<int> adj[n];

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int components = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                components++;

                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]) {

                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return components - 1;
    }
};