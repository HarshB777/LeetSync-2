class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> hm;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            int diff = target - num;

            if (hm.find(diff) != hm.end()) {
                return {hm[diff].back(), i};
            }
            hm[num].push_back(i);
        }

        return {};
    }
};