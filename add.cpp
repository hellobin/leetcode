/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra = 0;
        ListNode *p,*res = l1;
        while(l1 && l2)
        {
            l1->val = l1->val+l2->val+extra;
            extra = l1->val/10;
            if(extra)
            {
                l1->val %= 10;
            }
            p = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1) // l2 is less
        {
            if(extra)
            {
                while (extra && l1)
                {
                    l1->val += extra;
                    extra = l1->val/10;
                    l1->val %= 10;
                    p = l1;
                    l1 = l1->next;
                }
                if (extra)
                {
                    ListNode *n = new ListNode(extra);
                    p->next = n;
                }
            }
        }
        else if(l2) // l1 is less
        {
            p->next = l2;
            if(extra)
            {
                while (extra && l2)
                {
                    l2->val += extra;
                    extra = l2->val/10;
                    if(extra)
                    {
                        l2->val %= 10;
                    }
                    p = l2;
                    l2 = l2->next;
                }
                if (extra)
                {
                    ListNode *n = new ListNode(extra);
                    p->next = n;
                }
            }
        }
        else  // l1 equal to l2
        {
            if(extra)
            {
                ListNode *n = new ListNode(extra);
                p->next = n;
            }
        }
        return res;
    }
};