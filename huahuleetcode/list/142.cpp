/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution hashtable
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while(head) {
            if(seen.count(head)) return head;
            seen.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// Solution fast & slow pointer
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
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast, *slow;
        fast = slow = head;

        while(fast) {
            if(fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            else return nullptr;

            if(fast == slow) {
                break;
            }
        }
        
        if(fast == nullptr) return nullptr;

        // reference labuladong
        while(head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};