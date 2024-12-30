class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hm;
        for (char x: s)
        {
            hm[x]++;
        }
        for (char x: t)
        {
            hm[x]--;
            if (hm[x]==0)
            {
                hm.erase(x);
            }
        }

        return hm.size()==0;
    }
};