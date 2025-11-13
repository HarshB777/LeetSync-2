class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int n1 = 0, n0 = 0, l1;

        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            j = i;

            // count all ones to move in an op
            while (j < n && s[j] == '1') {
                j++;
            }

            n1 += j-i;

            if (j >= n) {
                break;
            }

            int f0 = j;
            while (j < n && s[j] == '0') {
                j++;
            }

            ans += n1;

            int n2 = j-f0;

            i = j;
        }

        return ans;
    }
};