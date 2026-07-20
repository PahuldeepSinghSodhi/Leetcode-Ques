class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);
        dist[src] = 0;
        //{stops,{node,dist}}
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if( stops > k){
                continue;
            }
            for(auto iter : adj[node]){
                int adjnode = iter.first;
                int edjwt = iter.second;
                if(cost + edjwt < dist[adjnode] && stops <=k){
                    dist[adjnode] = cost + edjwt ;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] != 1e9){
            return dist[dst];
        }
        return -1;
    }
};