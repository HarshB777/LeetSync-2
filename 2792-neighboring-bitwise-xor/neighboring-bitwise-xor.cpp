class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> org(n, -1);
        bool ans = false;
        org[0] = 0;

        for (int i = 1; i < n; i++) {
            
            if (derived[i-1] == 1)
            {
                if (org[i-1] == 1)
                    org[i] = 0;
                else
                    org[i] = 1;
            }
            else
            {
                org[i] = org[i-1];
            }
        }

        int xo = org[n-1] ^ org[0];
        if (xo == derived[n-1])
        {
            return true;
        }
        return false;


    }
};