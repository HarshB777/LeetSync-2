class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCnt = 0;
        for (int x: nums)
        {
            oneCnt += x;
        }

        int minSwaps = INT_MAX;

        //number of zeroes in window ==> ultimately number of swaps to be made
        int windowCnt = 0;
        for (int i = 0; i < oneCnt; i++)
        {
            if (nums[i] == 0)
            {
                windowCnt++;
            }
        }
        minSwaps = min(minSwaps, windowCnt);

        int n = nums.size();
        for (int i = oneCnt; i < n + oneCnt; i++)
        {
            if (nums[i%n] == 0)
            {
                windowCnt++;
            }

            if (nums[(i-oneCnt+n)%n] == 0)
            {
                windowCnt--;
            }

            minSwaps = min(windowCnt, minSwaps);
        }

        return minSwaps;


        return oneCnt;
    }
};