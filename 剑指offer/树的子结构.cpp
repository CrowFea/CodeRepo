/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool cert(TreeNode* t1,TreeNode* t2){
        if(t2==NULL)    return true;
        if(t1==NULL)    return false;
        if(t1->val!=t2->val)    return false;
        return cert(t1->left,t2->left)&&cert(t1->right,t2->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1==NULL||pRoot2==NULL)    return false;
        return cert(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
};