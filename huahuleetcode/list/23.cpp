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
// Solution multiset
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> nodes;
        for(auto list : lists) {
            while(list) {
                nodes.insert(list->val);
                list = list->next;
            }
        }

        ListNode dummy;
        ListNode *p = &dummy;
        for(auto it = nodes.begin(); it != nodes.end(); ++it) {
            ListNode *n = new  ListNode(*it);
            p->next = n;
            p = p->next;
        }

        return dummy.next;
        
    }
};

// Solution priority_queue 
// not optimal
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> nodes;
        for(auto list : lists) {
            while(list) {
                nodes.push(list->val);
                list = list->next;
            }
        }

        ListNode dummy;
        ListNode *p = &dummy;
        while(nodes.size()) {
            p->next = new ListNode(nodes.top());
            nodes.pop();
            p = p->next;
        }

        return dummy.next;
        
    }
};

// Solution mergeSort
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);  
    }

    ListNode* merge(vector<ListNode*>& lists, int l ,int r) {
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        if(l + 1 == r) return mergeTwoLists(lists[l], lists[r]);

        int m = l + (r - l) / 2;
        auto left = merge(lists, l, m);
        auto right = merge(lists, m + 1, r);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2) {
            if(l1->val > l2->val) swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};