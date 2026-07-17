class Solution {

    private:

    void combination(int n, int k, vector<int>& current, vector<vector<int>>& result, int idx){
        if(current.size() == k){
            result.push_back(current);
            return;
        }
        for(int i = idx ; i <= n ; i++){
            current.push_back(i);
            combination(n,k,current,result,i+1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> result;
        combination(n,k,current,result,1);
        return result;
        
    }
};