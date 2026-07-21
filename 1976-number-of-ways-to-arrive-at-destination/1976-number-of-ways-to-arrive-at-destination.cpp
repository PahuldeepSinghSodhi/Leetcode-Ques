class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int MOD = (int)1e9+7;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d>dist[node]){
                continue;
            }

           
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edjwt = it.second;
                //coming here for the first time
                if(d+edjwt < dist[adjnode]){
                    dist[adjnode] = d + edjwt;
                    pq.push({d + edjwt,adjnode});
                    ways[adjnode] = ways[node];
                }
                else if (d+edjwt == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1]%MOD;
    }
};