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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0, head);
        ListNode* p = &dummy;
        ListNode* q = head;
        ListNode* r = q->next;

        while(q && r) { 
            q->next = r->next;
            r->next = q;
            p->next = r;
            if(q->next && q->next->next) {
                p = q;
                q = q->next;
                r = q->next;
            }
        }
        
        return dummy.next;
    }
};