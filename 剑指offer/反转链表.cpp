/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL)    return pHead;
        ListNode *pre=NULL,*cur=NULL;
        while(pHead->next!=NULL){
            cur=pHead->next;
            pHead->next=pre;
            pre=pHead;
            pHead=cur;
        }
        pHead->next=pre;
        return pHead;
    }
};