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
        ListNode dummy;
        ListNode* p = &dummy;

        int sz1 = getSize(l1), sz2 = getSize(l2);
        list<int> rev_digits;
        
        while(l1 || l2) {
            if(sz1 > sz2) {
                rev_digits.push_back(l1->val);
                // p->next = new ListNode(l1->val);
                // p = p->next;
                l1 = l1->next;
                sz1--;
            }
            else if(sz1 < sz2) {
                rev_digits.push_back(l2->val);
                // p->next = new ListNode(l2->val);
                // p = p->next;
                l2 = l2->next;
                sz2--;
            }
            else {
                rev_digits.push_back(l1->val + l2->val);
                // p->next = new ListNode(l1->val + l2->val);
                // p = p->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        int asc = 0;
        for(auto it = rev_digits.rbegin(); it != rev_digits.rend(); ++it) {
            int sum = asc + *it;
            asc = sum / 10;
            *it = sum % 10;
        }
        if(asc != 0) {
            rev_digits.insert(rev_digits.begin(), asc);
        }
        
        for(auto i : rev_digits) {
            p->next = new ListNode(i);
            p = p->next;
        }
        
        return dummy.next;
    }

    int getSize(ListNode* l) {
        int sz = 0;
        while(l) {
            sz++;
            l = l->next;
        }
        return sz;
    }
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1;
    stack<int> s2;
    while(l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }   
    while(l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    ListNode* head = nullptr;
    int sum = 0;
    while(s1.size() || s2.size() || sum) {
        sum += s1.size() == 0 ? 0 : s1.top();
        sum += s2.size() == 0 ? 0 : s2.top();
        if(s1.size()) s1.pop();
        if(s2.size()) s1.pop();
        ListNode* n = new ListNode(sum % 10);
        sum /= 10;
        n->next = head;
        head = n;
    }

    return head;
  }
};