class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> hm;

        for (string x: strs)
        {
            string z = x;
            sort(x.begin(),x.end());
            hm[x].push_back(z);
        }
        vector<vector<string>> ans;
        for (auto [x,y]: hm)
        {
            vector<string> curr;
            for (auto z: y)
            {
                curr.push_back(z);
            }

            ans.push_back(curr);
        }
        return ans;

        
    }
};