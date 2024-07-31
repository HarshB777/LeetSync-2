class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);

        

        for (int i = 1; i < n-1; i++)
        {
            left[i] = left[i-1]*nums[i-1];
            right[n-i-1] = right[n-i]*nums[n-i];
        }
        left[n-1] = left[n-2]*nums[n-2];
        right[0] = right[1]*nums[1];

        for (int x: left)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        for (int x: right)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        vector<int> ans(n,1);

        for (int i = 0; i < n; i++)
        {
            ans[i] = left[i]*right[i];
        }

        return ans;
    }
};