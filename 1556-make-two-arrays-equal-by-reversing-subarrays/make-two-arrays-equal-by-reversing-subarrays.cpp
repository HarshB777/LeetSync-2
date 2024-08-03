class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> actual;

        for (int x: arr)
        {
            actual[x]++;
        }

        for (int x: target)
        {
            if (actual.find(x) == actual.end())
            {
                return false;
            }
            actual[x]--;
            if (actual[x] == 0)
            {
                actual.erase(x);
            }
        }

        return actual.empty();
    }
};