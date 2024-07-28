class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm; //num, freq
        

        for(int x: nums)
        {
            hm[x]++;
        }

        priority_queue<pair<int,int>> pq;
        for (auto [x,y]: hm)
        {
            pq.push({y,x});
        }
        hm.clear();
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            auto [freq, ele] = pq.top();
            pq.pop();

            ans.push_back(ele);
        }

        
    



        return ans;
    }
};