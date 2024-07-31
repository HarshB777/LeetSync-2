class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int p1 = 0, p2 = n-1;
        int max_area = 0;
        while (p1 < p2)
        {
            int curr_area = (p2-p1);
            if (height[p1] > height[p2])
            {
                curr_area *= min(height[p1],height[p2]);
                p2--;
            }
            else if (height[p2] > height[p1])
            {
                curr_area *= min(height[p1], height[p2]);
                p1++;
            }
            else
            {
                curr_area *= height[p1];
                p1++;
            }
            max_area = max(max_area,curr_area);
        }

        return max_area;
        
    }
};