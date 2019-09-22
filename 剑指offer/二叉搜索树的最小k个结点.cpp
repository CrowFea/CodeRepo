/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL)    return NULL;
        stack<TreeNode*> s;
        TreeNode* p=pRoot;
        int count=0;
        while(!s.empty()||p)
        {
            while(p){
                s.push(p);
                p=p->left;
            }
            if(!s.empty()){
                p=s.top();
                ++count;
                if(count==k)    return p;
                s.pop();
                p=p->right;
            }
        }
        return NULL;
    }
    
};