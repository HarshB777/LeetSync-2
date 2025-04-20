class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int sz = nums.size();
        int ans = 1;


        while (j < sz) {
            j = i+1;
            int prev_val = nums[i];
            int curr_cnt = 1;
            while (j < sz && nums[j] - nums[j-1] <= 1) {
                if (prev_val != nums[j]) {
                    curr_cnt++;
                }
                prev_val = nums[j];
                j++;
            }

            ans = max(curr_cnt, ans);
            i = j;
        }

        return ans;


    }
};