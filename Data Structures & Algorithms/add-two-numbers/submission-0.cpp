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
        // Dummy node to start the result list
        ListNode* dummy = new ListNode(0);
        // Pointer to build the result list
        ListNode* curr = dummy ;
         // Carry for addition
        int carry = 0;
        
        // Loop until both lists are finished and no carry is left
        while(l1 != NULL || l2!= NULL || carry){
            int sum = carry; //start with carry
            // Add value from l1 if it exists
            if(l1 != NULL){
              sum += l1->val;
              l1 = l1->next;
            }
            // Add value from l2 if it exists
             if(l2 != NULL){
              sum += l2->val;
              l2 = l2->next;
            }

            //update carry
            carry = sum/10;
            // Create new node with last digit of sum
            curr->next = new ListNode(sum%10);
            //move current pointer forward
            curr = curr->next;
        }
           // Return head of the result list (skip dummy node)
        return dummy->next;
    }
};

