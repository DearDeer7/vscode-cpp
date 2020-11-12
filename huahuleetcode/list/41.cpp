/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution fast & slow pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;

        while(fast && slow) {
            if(fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            else return false;
            if(fast == slow) return true;
        }

        return false;
    }
};

// Solution hashtable
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while(head) {
            if(seen.count(head)) return false;
            seen.insert(head);
            head = head->next;
        }
        return true;
    }
};