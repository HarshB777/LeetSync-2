class Solution {
public:
    int help(int idx, int curr, vector<vector<int>> &dp, int ans, vector<int> nums, int target)
    {

        if (idx == nums.size())
        {
            if (curr == target)
            {
                return 1;
            }
            return 0;
        }

        if (dp[idx][curr+1000] != -1)
        {
            return dp[idx][curr+1000];
        }
        int adder = help(idx+1,curr+nums[idx],dp,ans,nums,target);
        int subtracter = help(idx+1, curr-nums[idx], dp,ans,nums,target);

        return dp[idx][curr+1000] = adder + subtracter;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr = 0, idx = 0;
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2000,-1));
        return help(idx,curr,dp, ans, nums, target);
    }
};