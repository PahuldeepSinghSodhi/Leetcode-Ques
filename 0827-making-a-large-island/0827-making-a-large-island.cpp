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
    private:
    bool IsValid(int newr,int newc,int n){
        return newr >= 0 && newc >= 0 && newr < n && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        //step1 unioning the alr ones

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 0) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                for(int ind = 0 ; ind < 4 ; ind++){
                    int newr = row + drow[ind];
                    int newc = col + dcol[ind];
                    if(IsValid(newr,newc,n) && grid[newr][newc] == 1){
                    int node = row*n+col;
                    int adjnode = newr*n+newc;
                        ds.unionbysize(node,adjnode);
                    }
                }
            }
        }

        //step 2 check 0->1 combos
        int mx = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                set<int> components;
                for(int ind = 0 ; ind < 4 ; ind++){
                    int newr = row + drow[ind];
                    int newc = col + dcol[ind];
                    if(IsValid(newr,newc,n) && grid[newr][newc] == 1){
                    int node = row*n+col;
                    int adjnode = newr*n+newc;
                    components.insert(ds.findparent(adjnode));
                    }
                }
                int sizze=0;
                for(auto it : components){
                    sizze += ds.size[it];
                }

                mx = max(mx,sizze + 1);
            }
        }

        for(int i = 0 ; i < n*n ; i++){

            mx = max(mx,ds.size[ds.findparent(i)]);
        }

        return mx;
    }
};