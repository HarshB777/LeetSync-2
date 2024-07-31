class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p1 = 0, p2 = n-1;

        while (p1 < p2)
        {
            int cs = numbers[p1] + numbers[p2];
            if (cs == target)
            {
                return {p1+1,p2+1};
            }

            if (cs > target)
            {
                p2--;
            }
            else
            {
                p1++;
            }
        }


        return {p1,p2};
    }
};