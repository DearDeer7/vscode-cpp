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
        // 链表为空或有一个元素，则无环
        if(!head || !head->next) return nullptr; 
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        
        if(fast == nullptr) return nullptr;

        while(head != slow) {
            head = head->next;
            slow = slow->next;
        }
        
        return head;
    }
};