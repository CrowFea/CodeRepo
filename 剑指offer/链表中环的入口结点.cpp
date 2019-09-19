/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL||pHead->next->next==NULL)    return NULL;
        ListNode* fast=pHead->next->next;
        ListNode* slow=pHead->next;
        while(fast!=slow){
            if(fast->next&&fast->next->next){
                fast=fast->next->next;
                slow=slow->next;
            }
            else    return NULL;
        }
        fast=pHead;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};