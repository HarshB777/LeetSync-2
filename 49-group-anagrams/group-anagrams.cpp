class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> hm;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            string x = strs[i];
            sort(x.begin(),x.end());
            hm[x].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto x: hm)
        {
            vector<string> curr;
            
            for (int i: x.second)
            {
                curr.push_back(strs[i]);
            }
            ans.push_back(curr);
        }

        return ans;
    }
};