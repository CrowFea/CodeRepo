/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        ListNode *p=head;
        while(p){
            res.push_back(p->val);
            p=p->next;
        }
        for(int i=0,j=res.size()-1;i<j;++i,--j){
            int t=res[i];
            res[i]=res[j];
            res[j]=t;
        }
        return res;
    }
};