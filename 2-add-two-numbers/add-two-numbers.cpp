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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* it = NULL;

        //ans root node -> next starts the list
        ListNode* ans_root = NULL;
        ans_root = new ListNode(0);
        

        int v1 = p1->val, v2 = p2->val;
        int cs = v1+v2;
        int carry = 0;
        if (cs >= 10)
        {
            carry += cs/10;
        }

        
        it = new ListNode(cs % 10);
        ans_root->next = it;
        cout<<"it -> val = "<<it->val<<endl;
        p1 = p1->next;
        p2 = p2->next;

        
        
        while (p1 != NULL && p2 != NULL)
        {
            int v1 = p1->val;
            int v2 = p2->val;
            p1 = p1 -> next;
            p2 = p2->next;
            int cs = v1+v2+carry;
            carry = 0;
            if (cs >= 10)
            {
                carry += cs/10;
            }

            ListNode* curr = NULL;
            curr = new ListNode(cs % 10);
            cout<<"it here was => "<<it->val<<endl;
            it->next = curr;
            it = it->next;
            cout<<"it now is => "<<it->val<<endl;
            cout<<endl;
        }

        while (p1 != NULL)
        {
            int v1 = p1->val;
            p1 = p1->next;
            int cs = v1 + carry;
            carry = 0;

            if (cs >= 10)
            {
                carry += cs/10;
            }

            ListNode* curr = NULL;
            curr = new ListNode(cs % 10);

            it->next = curr;
            it = it->next;
        }

        while (p2 != NULL)
        {
            int v2 = p2->val;
            p2 = p2->next;
            int cs = v2 + carry;
            carry = 0;

            if (cs >= 10)
            {
                carry += cs/10;
            }

            ListNode* curr = NULL;
            curr = new ListNode(cs % 10);

            it->next = curr;
            it = it->next;
        }


        
        while (carry > 0)
        {
            int cs = carry % 10;
            carry = 0;
            carry += carry/10;


            ListNode* curr = NULL;
            curr = new ListNode(cs);

            it->next = curr;
            it = it->next;
        }
        

        return ans_root->next;

        


    }
};