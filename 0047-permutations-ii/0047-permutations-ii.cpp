class Solution {

    private :

    void permutation(vector<int>& nums, vector<int>& current,vector<vector<int>>& result, vector<bool>& used ){
        if(current.size() == nums.size()){
            result.push_back(current);
            return ;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(used[i]) continue;

            if(i>0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            current.push_back(nums[i]);
            used[i] = true;

            permutation(nums,current,result,used);

        current.pop_back();
        used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> current;
        vector<vector<int>> result;
        vector<bool> used(nums.size(),false)  ;
        permutation(nums,current,result,used);

        return result;
        
          }
};