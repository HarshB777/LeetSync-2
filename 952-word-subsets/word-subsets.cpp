class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> global_freq(26,0);
        vector<string> ans;
        for (string word: words2)
        {
            vector<int> f(26,0);

            for (char c: word)
            {
                f[c-'a']++;
                global_freq[c-'a'] = max(f[c-'a'], global_freq[c-'a']);
            }
        }

        for (int x: global_freq)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        
        for (string word: words1)
        {
            vector<int> freq(26,0);
            for (char x: word)
            {
                freq[x-'a']++;
            }

            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < global_freq[i]) {
                    flag = false;
                }
            }

            if (flag)
                ans.push_back(word);
        }

        return ans;

        
    }
};