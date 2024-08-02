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
    void deleteNode(ListNode* node) {
        ListNode *temp =node->next;
        // while(temp->next -> next != NULL){
        //     temp -> val = temp->next->val;
        //     temp = temp->next;
        // }
        node-> val = node->next->val;
        node->next = node->next->next;
        delete temp;

    }
};