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
 // Helper function to merge two sorted linked lists
 ListNode* merge(ListNode* l1 , ListNode* l2){
    ListNode dummy(0);
    ListNode* temp = &dummy;

    while(l1 != NULL && l2 != NULL ){
        //compare both list and merge in shorted order
        if(l1->val <= l2->val){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
             temp->next = l2;
             l2 = l2->next;
        }
        temp = temp->next ;
    }
    //attach remaining nodes
    if(l1 != NULL){
        temp->next = l1;
    }
    if(l2 != NULL){
        temp->next = l2;
    }
    return dummy.next;

 }
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size() == 0){
        return NULL ;
       }
       
       ListNode* ans = lists[0];
       
        for (int i = 1; i < lists.size(); i++) {
            ans = merge(ans, lists[i]);
        }
     return ans;
    }
};
