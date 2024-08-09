class Solution {
public:
    void help(int curr, int n, int &ans)
    {
        if (curr == n)
        {
            ans++;
            return;
        }

        if (curr + 2 <= n)
        {
            help(curr+2,n,ans);
        }

        help(curr+1,n,ans);


    }

    int memo(int curr, int n, vector<int> &dp)
    {

        
        if (curr == n)
        {
            return 1;
        }

        if (dp[curr] != -1)
        {
            return dp[curr];
        }
        
        int two = 0, one = 0;

        if (curr + 2 <= n)
        {
            two = memo(curr+2,n,dp);
        }
        one = memo(curr+1,n,dp);

        dp[curr] = one + two;

        return dp[curr];

    }
    int climbStairs(int n) {
        int ans = 0;
        //recursive solutions
        //help(0, n, ans);
        //return ans;


        //memoization
        //vector<int> dp(n,-1);
        //return memo(0, n, dp);

        //tabulation
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};