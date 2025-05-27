class Solution {
public:
    int differenceOfSums(int n, int m) {
        int s1 = n*(n+1)/2;
        int div = n/m;
        int s2 = (div) * (m + (m*div));
        s2 /= 2;

        // cout << "S1  = " << s1 << "  s2 = " << s2 << endl;

        return s1-s2-s2;
    }
};