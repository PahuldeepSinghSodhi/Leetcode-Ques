class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // best[node] = fewest stops used to reach 'node' among states already processed
        vector<int> best(n, INT_MAX);

        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto ii = pq.top();
            pq.pop();
            int cost = ii.first;
            int node = ii.second.first;
            int stops = ii.second.second;
            
            if(node == dst){
                return cost;
            }
            if(stops > k){
                continue;
            }
            // if we've already reached this node with fewer-or-equal stops,
            // this path can't be better — skip it
            if(stops >= best[node]){
                continue;
            }
            best[node] = stops;
            
            for(auto it : adj[node]){
                int price = cost + it.second;
                pq.push({price,{it.first, stops+1}});
            }
        }
        return -1;
    }
};