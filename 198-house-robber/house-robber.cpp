class Solution {
public:
    int memo(int idx, vector<int> &nums, vector<int> &dp) {

        if (idx >= nums.size()) {
            return 0;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }


        int take = 0, dont = 0;
        take = nums[idx] + memo(idx + 2, nums, dp);
        dont = memo(idx+1,nums,dp);

        return dp[idx] = max(take ,dont);
    }
    int rob(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        vector<int> dp(n,-1);

        return memo(idx,nums,dp);
    }
};