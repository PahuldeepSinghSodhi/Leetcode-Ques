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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return NULL;
        ListNode* temp=head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(temp!=NULL){
            if(temp->next !=NULL && temp->val == temp->next->val){
                int dupval = temp->val;
                while(temp!=NULL && temp->val == dupval){
                    temp = temp->next;
                }
                prev->next = temp;
            }
            else{
                prev = temp;
                temp = temp->next;
            }            
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};