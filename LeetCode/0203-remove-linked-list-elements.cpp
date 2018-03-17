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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;
        if( head == NULL ) return head;
        if( head->next == NULL ) return head->val == val ? NULL : head;
        
        ListNode *prev = head, *cur = head->next;
        for(; cur; cur = cur->next){
            if(cur->val == val){
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};