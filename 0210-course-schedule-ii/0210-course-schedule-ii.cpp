class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses,0);
        vector<int>  pre[numCourses];

        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];
            // b -> a
            pre[b].push_back(a); //b->{a}
        }
        for(int i = 0 ; i < numCourses ; i++){
            for(auto it : pre[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            ans.push_back(node);
            
            for(auto it : pre[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(cnt == numCourses){
            return ans;
        }
        else return {};
        
    }
};