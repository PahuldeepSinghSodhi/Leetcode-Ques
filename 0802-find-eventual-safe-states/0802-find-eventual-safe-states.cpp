class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> revAdj[V];
vector<int> indegree(V, 0);

        // Reverse the graph
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // Push all terminal nodes
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : revAdj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(topo.begin(), topo.end());

        return topo;
    }
};