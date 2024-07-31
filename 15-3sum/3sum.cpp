class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        set<vector<int>> hs;
        int n = nums.size();
        for (int i = 0; i < n-2; i++)
        {
            int csum = nums[i];
            int p1 = i+1;
            int p2 = n-1;

            while (p1 < p2)
            {
                csum = nums[i] + nums[p1] + nums[p2];
                
                if (csum == 0)
                {
                    //v.push_back({nums[i], nums[p1], nums[p2]});
                    hs.insert({nums[i],nums[p1],nums[p2]});
                    p1++;
                    p2--;
                    continue;
                }

                if (csum > 0)
                {
                    p2--;
                }
                else
                {
                    p1++;
                }

            }
        }
        for (auto x: hs)
        {
            v.push_back(x);
        }
        return v;
    }
};