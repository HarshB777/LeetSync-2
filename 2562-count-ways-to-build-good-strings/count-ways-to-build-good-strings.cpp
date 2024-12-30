class Solution {
public:
    int mx = 1e9+7;
    int ans = 0;
    
    int help(int curr_length, int &low, int &high, int &zero, int &one, vector<int> &dp)
    {
        if (curr_length > high)
        {
            return 0;
        }
        if (dp[curr_length] != -1)
        {
            return dp[curr_length];
        }
        int here = 0;
        if (curr_length > high)
        {
            return 0;
        }
        if (curr_length >= low && curr_length <= high)
        {
            here++;
        }

        here = (here%mx + help(curr_length + zero, low, high, zero, one, dp)%mx)%mx;
        here = (here % mx + help(curr_length + one, low, high, zero, one, dp)%mx)%mx;
        // cout<<"here = "<<here<<endl;
        dp[curr_length] = here;

        return here;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        
        int curr_length = 0;
        vector<int> dp(high+1,-1);
        return help(curr_length, low, high, zero, one, dp);
        
    }
};