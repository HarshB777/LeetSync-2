class Solution {
public:
    int help(vector<int> prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2, vector<int> (k+1,0)));

        for (int idx = n-1; idx >= 0; idx--)
        {
            for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
            {
                for (int buyCnt = 0; buyCnt < k; buyCnt++)
                {
                    int maxi = 0;
                    int ntg = dp[idx+1][buyFlag][buyCnt];
                    maxi = max(maxi, ntg);

                    if (buyFlag)
                    {
                        int buy = -prices[idx] + dp[idx+1][0][buyCnt];
                        maxi = max({maxi,buy,ntg});
                    }
                    else
                    {
                        int sell = prices[idx] + dp[idx+1][1][buyCnt+1];
                        maxi = max({maxi,sell,ntg});
                    }
                    dp[idx][buyFlag][buyCnt] = maxi;
                }
            }
        }

        return dp[0][1][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        return help(prices,k);
    }
};