# Number of islands II

**Platform:** TakeYouForward  
**Date:** 2026-07-31  

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
class Solution{
    private:
    bool IsValid(int adjr,int adjc,int n,int m){
        return adjr >=0 && adjc >= 0 && adjr < n && adjc < m;
    }
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){

    DisjointSet ds(n*m);
    int vis[n][m];
   memset(vis,0,sizeof (vis));
    int cnt = 0;
    vector<int> ans;
    for(auto it : A){
        int row = it[0];
        int col = it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i = 0 ; i < 4 ; i++){
            int adjr = row + dx[i];
            int adjc = col + dy[i];
            if(IsValid(adjr,adjc,n,m) && vis[adjr][adjc] == 1){
                int node = row * m + col;
                int adjnode = adjr * m + adjc;
                if(!ds.find(node,adjnode)){
                    cnt--;
                    ds.unionbysize(node,adjnode);
                }
            }
        }
        ans.push_back(cnt);
    }      
    return ans;  
    }
};
```
