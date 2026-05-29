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

    // Function to find length of linked list
    int len(ListNode* head) {
        int cnt = 0;

        // FIX: && instead of ||
        while (head != NULL) {
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Find length of linked list
        int length = len(head);

        // Edge Case: remove first node
        if (length == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Reach node before target node
        int pos = length - n - 1;

        ListNode* curr = head;

        while (pos > 0) {
            curr = curr->next;
            pos--;
        }

        // Remove node
        ListNode* temp = curr->next->next;
        delete(curr->next);
        curr->next = temp;

        // FIX: return head
        return head;
    }
};
