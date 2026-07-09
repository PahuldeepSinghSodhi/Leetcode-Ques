class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Create directed graph
        for(auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push courses having no prerequisite
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            cnt++;

            for(auto adjnode : adj[node]) {

                indegree[adjnode]--;

                if(indegree[adjnode] == 0) {
                    q.push(adjnode);
                }
            }
        }

        if(cnt == numCourses)
            return true;

        return false;
    }
};