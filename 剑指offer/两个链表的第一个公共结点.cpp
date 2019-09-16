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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL)    return NULL;
        ListNode *p1=pHead1,*p2=pHead2;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
            if(p1!=p2){
                if(p1==NULL)    p1=pHead1;
                if(p2==NULL)    p2=pHead2;
            }
        }
        return p1;
    }
};