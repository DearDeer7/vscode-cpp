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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        stack<int> s;
        ListNode* p = head;
        while(p) {
            s.push(p->val);
            p = p->next;
        }

        p = head;
        while(s.size()) {
            p->val = s.top(); s.pop();
            p = p->next;
        }

        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = new ListNode();
        
        ListNode* q = head;
        while(q) {
            ListNode* n = q->next;
            q->next = p->next;
            p->next = q;
            q = n;
        }
        

        return p;
    }
};