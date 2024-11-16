#include <deque>
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        map<int,int> hm;
        vector<int> ans(n-k+1,-1);
        for(int i = 0; i < k; i++)
        {
            dq.push_back(nums[i]);
            hm[nums[i]]++;
        }

        int st = hm.begin()->first;
        int ed = hm.rbegin()->first;

        int f = dq.front();
        int b = dq.back();

        if ((ed-st+1) == hm.size() && hm.size() == dq.size() && f == st && ed == b)
        {
            cout<<"inside if: ans of ["<<0<<"] = "<<ed<<endl;
            ans[0] = ed;
        } 

        cout<<"st = "<<st<<" ed = "<<ed<<" f = "<<f<<" b = "<<b<<endl;
        for (int i = k; i < n; i++)
        {
            dq.pop_front();
            dq.push_back(nums[i]);
            hm[nums[i-k]]--;
            if (hm[nums[i-k]] == 0)
            {
                hm.erase(nums[i-k]);
            }
            hm[nums[i]]++;

            st = hm.begin()->first;
            ed = hm.rbegin()->first;

            f = dq.front();
            b = dq.back();
            cout<<"st = "<<st<<" ed = "<<ed<<" f = "<<f<<" b = "<<b<<endl;
            if ((ed-st+1) == hm.size() && hm.size() == dq.size() && f == st && ed == b)
            {
                cout<<"inside if: ans of ["<<(i-k)<<"] = "<<ed<<endl;
                ans[i-k+1] = ed;
            }
            
        }

        return ans;
    }
};