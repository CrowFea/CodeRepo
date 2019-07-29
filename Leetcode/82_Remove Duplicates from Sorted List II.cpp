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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=new ListNode(0);
        p->next=head;
        head=p;
        ListNode* pre,*cur;
        while(p->next){
            cur=p->next;
            pre=cur;
            while(cur->next&&cur->next->val==pre->val){
                cur=cur->next;
            }
            if(pre==cur)    p=p->next;
            else p->next=cur->next;
        }
        return head->next;
    }
};