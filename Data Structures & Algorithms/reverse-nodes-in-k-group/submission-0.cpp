class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check whether k nodes are present
        ListNode* temp = head;
        int n = k;

        while(n > 0 && temp != NULL){
            temp = temp->next;
            n--;
        }

        // Less than k nodes -> don't reverse
        if(n > 0)
            return head;

        // Save the next group
        ListNode* nextGroup = temp;

        // Cut current k nodes from remaining list
        temp = head;
        n = k;

        while(n > 1){
            temp = temp->next;
            n--;
        }

        temp->next = NULL;

        // Reverse current k nodes
        ListNode* newHead = reverse(head);

        // Recursively reverse remaining groups
        ListNode* newTail = head;
        newTail->next = reverseKGroup(nextGroup, k);

        return newHead;
    }
};