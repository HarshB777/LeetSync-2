class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hm1;
        unordered_map<char,int> hm2;

        for (char x: s)
        {
            hm1[x]++;
        }   
        for (char x: t)
        {
            hm2[x]++;
        }

        for (auto [x,y]: hm1)
        {
            cout<<x<<endl;
            if (hm2.find(x) == hm2.end())
                return false;
            if (hm2[x] != y)
                return false;
            hm2.erase(x);
        }

        if (!hm2.empty())
        {
            return false;
        }

        return true;
    }
};