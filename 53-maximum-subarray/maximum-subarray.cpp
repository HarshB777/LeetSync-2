class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        int cs = 0;
        for (int i=0; i<n; i++) {
            if (cs < 0) {
                cs = 0;
            }
            cs+=nums[i];
            maxi = max(maxi, cs);
        }

        return maxi;



    }
};