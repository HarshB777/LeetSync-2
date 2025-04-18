class Solution {
public:
    int sz;
    vector<int> ans;
    vector<int> vec;


    void computeProductExceptSelf() {
        ans.resize(sz, 1);
        
        // multiply element before it
        int leftProduct = 1;
        for (int i = 1; i < sz; i++)
        {
            leftProduct *= vec[i-1];
            ans[i] *= leftProduct;
        }
        
        // multiply element after it
        int rightProduct = 1;
        for (int i = sz-2; i >= 0; i--)
        {
            rightProduct *= vec[i+1];
            ans[i] *= rightProduct;
        }
    }


    vector<int> productExceptSelf(vector<int>& nums) {
        vec = nums;
        sz = nums.size();

        computeProductExceptSelf();
        return ans;
    }
};