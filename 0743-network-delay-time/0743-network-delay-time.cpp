class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        queue<pair<int,int>> q;
        vector<pair<int,int>> adj[n+1];

        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        //{node,dist}
        q.push({k,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int d = it.second;

            for(auto iter : adj[node]){
                int adjnode = iter.first;
                int edjwt = iter.second;

                if(d + edjwt < dist[adjnode]){
                    dist[adjnode] = d + edjwt;
                    q.push({adjnode,dist[adjnode]});
                }
            }
        }
        int ans = *max_element(dist.begin() +1,dist.end());
        if(ans == 1e9){
            return -1;
        }
        return ans;
        
    }
};