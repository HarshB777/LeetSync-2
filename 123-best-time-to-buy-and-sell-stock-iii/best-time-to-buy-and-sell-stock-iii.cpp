class Solution {
public:
    int help(vector<int> prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));

        for (int i = n-1; i >= 0; i--)
        {
            for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
            {
                for (int buyCnt = 0; buyCnt <= 1; buyCnt++)
                {
                    int maxi = 0;
                    int ntg = dp[i+1][buyFlag][buyCnt];
                    maxi = max(maxi, ntg);

                    if (buyFlag)
                    {
                        int buy = -prices[i] + dp[i+1][0][buyCnt];
                        maxi = max(maxi,buy);
                    }
                    else
                    {
                        int sell = prices[i] + dp[i+1][1][buyCnt + 1];
                        maxi = max(maxi,sell);
                    }

                    dp[i][buyFlag][buyCnt] = maxi;
                }
            }
        }

        return dp[0][1][0];
    }
    int maxProfit(vector<int>& prices) {
        return help(prices);
    }
};