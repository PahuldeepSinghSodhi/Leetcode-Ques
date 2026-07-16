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
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        while(fast != NULL && fast->next != NULL){
            dummy=dummy->next;
            fast=fast->next->next;
        }

        dummy->next = dummy->next->next;
        return head;
    
        
    }
};