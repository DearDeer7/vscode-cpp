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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> vals;
        while(head) {
            vals.push_back(head->val);
            head = head->next;
        }

        sort(vals.begin(), vals.end());

        ListNode dummy(0);
        ListNode *tail = &dummy;
        for(int i : vals) {
            tail->next = new ListNode(i);
            tail = tail->next;
        }

        return dummy.next;
    }
};