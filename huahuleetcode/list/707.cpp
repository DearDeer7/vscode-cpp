/**
 * https://leetcode.com/problems/design-linked-list/
 * author: DearDeer
 */
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList(): head(nullptr), tail(nullptr), size(0) {}
    ~MyLinkedList() {
        Node* node = head;
        while(node) {
            Node *cur = node;
            node = node->next;
            delete cur;
        }
        head = tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node *cur = head;
        while(index--) cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head = new Node(val, head);
        ++size;
        if(size == 1) {
            tail = head;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *n = new Node(val);
        ++size;
        if(size == 1) {
            head = tail = n;
        }
        else {
            tail->next = n;
            tail = tail->next;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) return addAtHead(val);
        if(index == size) return addAtTail(val);
        Node dummy(0, head);
        Node *pre = &dummy;
        while(index--) pre = pre->next;
        pre->next = new Node(val, pre->next);
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        Node dummy(0, head);
        Node *pre = &dummy;
        for(int i = 0; i < index; i++) 
            pre = pre->next;
        Node *del = pre->next;
        pre->next = pre->next->next;
        if(index == 0) {
            head = del->next;
        }
        else if(index == size - 1) {
            tail = pre;
        }
        delete del;
        --size;
    }
private:
    struct Node {
        int val; 
        Node *next;
        Node(int _val): Node(_val, nullptr) {}
        Node(int _val, Node* _next): val(_val), next(_next) {}
    };
    /**             head                       tail
     *                |                          |
     *                V                          V
     * linked list: node0->node1->node2->...->noden
     */

    Node *head, *tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */