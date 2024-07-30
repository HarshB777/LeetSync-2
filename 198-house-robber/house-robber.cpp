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

    vector<vector<int>> dp(n+1, vector<int> (n+2,0));

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = -2; j < i; j++)
        {
            int m1 = 0;
            int bb = 0, cc = 0;
            if (i - j != 1)
            {
                bb = nums[i] + dp[i+1][i+2];
                //m1 = max(m1,bb);
            }
            cc = dp[i+1][j+2];
            m1 = max(bb,cc);
            dp[i][j+2] = m1;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return dp[0][0];



}


    int rob(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+2,-1));
        return tab(nums);
    }
};