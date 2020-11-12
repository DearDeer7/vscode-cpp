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
        ListNode ans;
        ListNode* p = &ans;
        while(l1 || l2) {
            if(l1&& l2) {
                p->next = new ListNode(l1->val + l2->val);
                l1 = l1->next;
                l2 = l2->next;
                p = p->next;
            }
            else if(l1) {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
                p = p->next;
            }
            else if(l2) {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
                p = p->next;
            }
        }

        int asc = 0;
        p = ans.next;
        while(p->next) {
            p->val += asc;
            asc = p->val / 10;
            p->val %= 10;
            p = p->next;
        }
        p->val += asc;
        if(p->val >= 10) {
            p->next = new ListNode(p->val / 10);
            p->val %= 10;
        }
        return ans.next;
    }
};