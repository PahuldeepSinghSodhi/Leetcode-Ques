class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> adj(n + 1);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);

        queue<pair<int, int>> q;
        q.push({1, 0});
        dist1[1] = 0;

        while (!q.empty()) {
            auto [node, currTime] = q.front();
            q.pop();

            // Wait if signal is red
            if ((currTime / change) % 2 == 1) {
                currTime = (currTime / change + 1) * change;
            }

            int newTime = currTime + time;

            for (int next : adj[node]) {

                if (newTime < dist1[next]) {
                    dist2[next] = dist1[next];
                    dist1[next] = newTime;
                    q.push({next, newTime});
                }
                else if (newTime > dist1[next] && newTime < dist2[next]) {
                    dist2[next] = newTime;
                    q.push({next, newTime});
                }
            }
        }

        return dist2[n];
    }
};