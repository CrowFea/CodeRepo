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
    bool judge(TreeNode* left, TreeNode* right)
    {
        if(left == NULL)    return right == NULL;
        if(right == NULL) return false;
        if(left->val!=right->val) return false;
        return judge(left->left, right->right) && judge(left->right, right->left);
    }

    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL) return true;
        return judge(pRoot->left,pRoot->right);
    }

};