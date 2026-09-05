/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node* , Node* > mp;

        Node* newHead = new Node(head->val);
        Node* oldptr = head->next;
        Node* newptr = newHead;


        mp[head] = newHead;

        // simple copy of linked list
        while(oldptr != NULL){
            Node* copyNode = new Node(oldptr->val);
            mp[oldptr] = copyNode;

            newptr->next = copyNode;
            oldptr = oldptr->next;
            newptr = newptr->next;
        }

        oldptr = head , newptr = newHead;

        // copy with random pointer

        while(oldptr != NULL){
            newptr->random = mp[oldptr->random];
            oldptr = oldptr->next;
            newptr = newptr->next ;
        }

        return newHead;
    }
};
