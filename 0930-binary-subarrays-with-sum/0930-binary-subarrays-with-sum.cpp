class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int presum = 0,cnt=0;
        unordered_map <int,int> mpp;
        mpp[0] = 1;
        for(int i = 0 ; i < nums.size(); i++){
            presum += nums[i];
            int remove = presum - goal;
            cnt += mpp[remove];
            mpp[presum]++;
        }
        return cnt;
        
    }
};