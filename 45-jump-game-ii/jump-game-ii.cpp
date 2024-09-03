class Solution {
public:
    void help(int idx, int cnt, vector<int> &nums, int &mini)
    {
        if (idx >= nums.size()-1)
        {
            mini = min(mini, cnt);
            return;
        }

        for (int i = 1; i <= nums[idx]; i++)
        {
            help(idx+i,cnt+1,nums,mini);
        }
    }
    long long memo(int idx, vector<int> &nums, vector<long long> &dp)
    {
        if (idx >= nums.size()-1)
        {
            return 0;
        }

        if (dp[idx]!=-1)
        {
            return dp[idx];
        }
        long long fin = INT_MAX;
        for (long long i = 1; i <= nums[idx]; i++)
        {
            
            long long here = 1 + memo(idx+i,nums,dp);
            fin = min(fin,here);
        }


        return dp[idx] = fin;
    }
    int jump(vector<int>& nums) {
        int idx = 0, cnt = 0;
        int mini = INT_MAX;

        //help(idx,cnt,nums,mini);
        int n = nums.size();
        //vector<vector<int>> dp(n, vector<int> (n,-1));
        vector<long long> dp(n,-1);
        return int(memo(idx,nums,dp));

        return mini;
    }
};