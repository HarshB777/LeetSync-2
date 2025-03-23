class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int sq = n*n;
        int maxi = maxWeight / w;

        int wt = sq * w;

        if (wt  <= maxWeight) {
            return sq;
        }
        return maxi;
    }
};