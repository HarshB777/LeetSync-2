class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hm;
        for (string x: strs)
        {
            string tmp = x;
            sort(tmp.begin(), tmp.end());
            hm[tmp].push_back(x);
        }

        for (auto x: hm)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};