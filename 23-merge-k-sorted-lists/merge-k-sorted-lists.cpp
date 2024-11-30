/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>> pq;
        int n = lists.size();
        ListNode* ans = new ListNode(0);
        ListNode* it = NULL;
        map<int,ListNode*> hm;
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != NULL) {
                pq.push({-lists[i]->val, i});
                hm[i] = lists[i];
            }
        }

        while (!pq.empty())
        {
            int val = -pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (it == NULL)
            {
                it = new ListNode(val);
                ans->next = it;
            }
            else
            {
                ListNode* curr = new ListNode(val);
                it->next = curr;
                it = it->next;
            }

            hm[idx] = hm[idx]->next;
            if (hm[idx] == NULL)
            {
                hm.erase(idx);
            }
            else
            {
                pq.push({-hm[idx]->val, idx});
            }
        }


        return ans->next;



    }
};