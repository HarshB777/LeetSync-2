class Solution {
public:
    void help(int n, string s, int oc, int cc, vector<string> &ans)
    {
        if (s.size() == (2*n))
        {
            ans.push_back(s);
            return;
        }

        if (oc < n)
        {
            help(n,s+'(',oc+1,cc,ans);
        }
        if (cc < oc)
        {
            help(n,s+')',oc,cc+1,ans);
        }

        

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        help(n,"(",1,0,ans);

        return ans;
    }
};