class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hs;

        for (int x: nums)
        {
            if (hs.find(x) != hs.end())
            {
                return true;
            }
            hs.insert(x);
        }


        return false;


    }
};