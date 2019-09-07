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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *pre=pListHead,*p=pListHead;
        int i=0;
        while(p){
            if(i<k){
                p=p->next;
                ++i;
                if(p==NULL&&i<k)    return NULL;
                continue;
            }
            p=p->next;
            pre=pre->next;
        }
        return pre;
    }
};