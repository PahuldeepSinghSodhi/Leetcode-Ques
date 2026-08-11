class Solution {
private:
    long long f(int ind, vector<int>& nums, vector<int>& dp) {

        if (ind == 0)
            return nums[ind];

        if (ind < 0)
            return 0;

            if(dp[ind] != -1) return dp[ind];

        long long pick = nums[ind] + f(ind - 2, nums,dp);
        long long notpick = 0 + f(ind - 1, nums,dp);

        return dp[ind] = max(pick, notpick);
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+1,-1);

        return f(n - 1, nums, dp);
    }
};