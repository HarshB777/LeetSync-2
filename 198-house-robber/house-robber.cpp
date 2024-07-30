class Solution {
public:
    int help(vector<int> nums, int idx, int last, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
        {
            return 0;
        }
        int m1 = 0;
        if (idx - last != 1)
        {
            //help(nums,idx+1,idx,curr+nums[idx],dp);
            m1 = nums[idx]+help(nums,idx+1,idx,dp);
        }
        int m2 = help(nums,idx+1,last,dp);
        

        return dp[idx][last+2] = max(m1,m2);

    }


int tab(vector<int> nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    // Initialize dp table
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int last = -2; last < idx; last++) {
            int m1 = 0;
            if (idx - last != 1) {
                m1 = nums[idx] + dp[idx + 1][idx + 2];
            }
            int m2 = dp[idx + 1][last + 2];
            dp[idx][last + 2] = max(m1, m2);
        }
    }

    return dp[0][0];
}


    int rob(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+2,-1));
        return tab(nums);
    }
};