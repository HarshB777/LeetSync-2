class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ps(31,0);
        int n = nums.size();

        for (int x: nums)
        {
            for (int b = 0; b < 31; b++)
            {
                if ((x & 1<<b) != 0)
                {
                    ps[b]++;
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int rear = nums[n-i-1];
            int here = 0;
            for (int b = maximumBit-1; b >= 0; b--)
            {
                if (ps[b] % 2 == 0)
                {
                    here += (1<<b);
                }
            }

            ans[i] = here;

            for (int b = 30; b >= 0; b--)
            {
                if ((rear & 1<<b) != 0)
                {
                    ps[b]--;
                }
            }
        }         

        return ans;

    }
};