# Agree button ⬇

**Platform:** LeetCode  
**Date:** 2026-07-29  

## Solution

```
class DisjointSet { public: vector<int> parent, size, rank; DisjointSet(int n) { parent.resize(n); size.resize(n, 1); rank.resize(n, 0); for (int i = 0; i < n; i++) parent[i] = i; } int findparent(int node) { if (node == parent[node]) return node; return parent[node] = findparent(parent[node]); } bool find(int u, int v) { return findparent(u) == findparent(v); } void unionbyrank(int u, int v) { int pu = findparent(u); int pv = findparent(v); if (pu == pv) return; if (rank[pu] < rank[pv]) { parent[pu] = pv; } else if (rank[pv] < rank[pu]) { parent[pv] = pu; } else { parent[pv] = pu; rank[pu]++; } } void unionbysize(int u, int v) { int pu = findparent(u); int pv = findparent(v); if (pu == pv) return; if (size[pu] < size[pv]) { parent[pu] = pv; size[pv] += size[pu]; } else { parent[pv] = pu; size[pu] += size[pv]; } } };

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int MaxRows = 0;
        int MaxCols = 0;
        int n =0;
        for(auto it : stones){
            n++;
            MaxRows = max(it[0],MaxRows);
            MaxCols = max(it[1],MaxCols);
        }

        DisjointSet ds(MaxRows+MaxCols+2);
        unordered_map<int,int> stoneNodes;
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + MaxRows + 1;
            ds.unionbysize(noderow,nodecol);
            stoneNodes[noderow]=1;
            stoneNodes[nodecol]=1;
        }
        int cnt = 0;
        for(auto it : stoneNodes){
            if(ds.findparent(it.first) == it.first){
                cnt++;
            }
        }
        return n - cnt;
    }
};
```
