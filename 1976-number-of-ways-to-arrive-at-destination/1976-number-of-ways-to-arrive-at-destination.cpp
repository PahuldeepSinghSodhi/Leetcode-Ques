class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n];

        for(auto it : roads){
            //adj[from] = adj{to,weight}
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        const int MOD = 1e9+7;
        vector<int> ways(n,0);
        ways[0] = 1;
        vector<long long> dist(n,LLONG_MAX);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        dist[0] = 0;

        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            int node = it.second;

            if(d>dist[node]){
                continue;
            }

            for(auto iter : adj[node]){
                int adjnode = iter.first;
                int edjwt = iter.second;

                if(d + edjwt < dist[adjnode]){
                        dist[adjnode] = d + edjwt;
                        pq.push({d + edjwt,adjnode});
                        ways[adjnode] = ways[node];
                }
                else if (d + edjwt == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }
            return ways[n-1];

    }
};