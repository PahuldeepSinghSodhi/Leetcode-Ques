class Solution {

    private :

    void permutation(vector<int>& nums, vector<int>& current,vector<vector<int>>& result, int idx){
       
            result.push_back(current);
        
        for(int i = idx ; i < nums.size() ; i++){
            current.push_back(nums[i]);
            permutation(nums,current,result,i+1);

        current.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        permutation(nums,current,result,0);
              return result;
        
          }
};