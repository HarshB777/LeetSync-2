class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> hm;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int f = target-nums[i];
            if (hm.find(f) != hm.end())
            {
                return {hm[f].back(),i};
            }
            hm[nums[i]].push_back(i);
        }

        return {};
    }
};