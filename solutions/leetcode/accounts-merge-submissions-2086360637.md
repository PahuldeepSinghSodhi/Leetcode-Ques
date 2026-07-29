# accounts merge/submissions/2086360637

**Platform:** LeetCode  
**Date:** 2026-07-29  

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapmailnode;

        for(int i = 0; i < n ; i++){
            for(int j = 1; j < accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mapmailnode.find(mail) == mapmailnode.end()){
                    mapmailnode[mail] = i;
                }
                else {
                    ds.unionbysize(i,mapmailnode[mail]);
                }
            }
        }

        vector<string> mergedmail[n];
        for(auto it : mapmailnode){
            string mail = it.first;
           int  node = ds.findparent(it.second);
            mergedmail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;

        for(int i = 0 ; i < n ; i++){
            if(mergedmail[i].size() == 0) continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```
