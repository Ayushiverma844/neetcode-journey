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
    void reorderList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL){
            return ;
        }

        // step1 : find middle point
        //we will use slow and fast pointer , at the end slow pointer will be at the middle point
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next ;
            fast = fast->next->next;
        }

        //step2: reverse second half
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
          ListNode* forward = curr->next;
          curr->next = prev;
          prev = curr;
          curr = forward;
        }
        
        // step:3 merge 
        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL){

        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
}
    }
};
