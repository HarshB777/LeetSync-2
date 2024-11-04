class Solution {
public:
    string compressedString(string word) {
        int i = 0, j = 0;
        int n = word.size();
        string s = word;
        
        string ans = "";
        
        while (j < n)
        {
            j = i;
            
            while (j < n && (j - i <= 8) && (s[j] == s[i]))
                j++;
            
            ans += to_string(j-i);
            ans += s[i];
            i = j;
        }
        
        return ans;
    }
};