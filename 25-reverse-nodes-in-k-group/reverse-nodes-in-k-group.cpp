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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> buff;
        ListNode* it = head;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        while (it != NULL)
        {
            buff.push_back(it->val);
            if (buff.size() == k)
            {
                while (!buff.empty())
                {
                    curr->next = new ListNode(buff.back());
                    curr = curr->next;
                    buff.pop_back();
                }
            }
            it = it->next;
        }

        for (int x: buff)
        {
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return ans->next;


    }
};