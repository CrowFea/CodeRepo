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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p1=pHead1,*p2=pHead2;
        ListNode *head=new ListNode(0);
        ListNode *p=head;
        while(p1||p2){
            if(p2==NULL&&p1||p1&&p1->val<p2->val){
                p->next=new ListNode(p1->val);
                p1=p1->next;
                p=p->next;
                continue;
            }
            else{
                p->next=new ListNode(p2->val);
                p2=p2->next;
                p=p->next;
            }
        }
        p->next=NULL;
        return head->next;
    }
};