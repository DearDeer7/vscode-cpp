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
        // 链表为空或有一个元素，则无环
        if(!head || !head->next) return false; 
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            // 快慢指针相遇，则有环
            if(fast == slow) return true;
        }
		// 链表走完，快慢指针未相遇，则无环
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