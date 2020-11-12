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
// Solution mergeSort top-down
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        // return merge(sortList(head), sortList(mid));
        return merge(l1, l2);
    }

    ListNode* merge(ListNode *l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2) {
            if(l1 ->val > l2->val) swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Solution mergeSort bottom-up
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        int len = 1;
        ListNode *cur = head->next;
        while(cur) {
            len++;
            cur = cur->next;
        }

        ListNode dummy(0, head);
        ListNode *tail;
        ListNode *l, *r;
        for(int i = 1; i < len; i <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            while(cur) {
                l = cur;
                r = split(cur, i);
                cur = split(r, i);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }

        return dummy.next;
    }

    ListNode* split(ListNode* head, int n) {
        while(--n && head) head = head->next;
        ListNode *rest = head ? head->next : nullptr;
        if(head) head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        // if(!l1 || !l2) return l1 ? l1 : l2;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while(tail->next) tail = tail->next;
        return {dummy.next, tail};
    }
};