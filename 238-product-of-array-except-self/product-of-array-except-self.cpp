class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int rp = 1;
        int n = nums.size();
        vector<int> ans(n,1);
        for (int i = 1; i < n; i++)
        {
            rp*=nums[i-1];
            ans[i] *= rp;
        }

        rp = 1;
        for (int i = n-2; i >= 0; i--)
        {
            rp *= nums[i+1];
            ans[i] *= rp;
        }

        return ans;
    }
};