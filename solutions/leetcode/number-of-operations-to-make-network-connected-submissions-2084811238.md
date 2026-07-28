# number of operations to make network connected/submissions/2084811238

**Platform:** LeetCode  
**Date:** 2026-07-28  

## Solution

```
class DisjointSet {
public:
    vector<int> parent, size, rank;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findparent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findparent(parent[node]);
    }

    bool find(int u, int v) {
        return findparent(u) == findparent(v);
    }

    void unionbyrank(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionbysize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);
        int CntExtras = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.find(u,v)){
                CntExtras++;
            }
            else ds.unionbysize(u,v);
        }

        int CntC = 0;
        int ans;
        for(int i = 0; i < n ; i++){
            if(ds.parent[i] == i){
                CntC++;
            }
        }
        ans = CntC - 1;
        if(CntExtras >= ans) return ans;
        return -1;
        
    }
};
```
