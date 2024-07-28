class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26,0);

        for (char x: s)
        {
            vec[x-'a']++;
        }

        for (char x: t)
        {
            vec[x-'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (vec[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};