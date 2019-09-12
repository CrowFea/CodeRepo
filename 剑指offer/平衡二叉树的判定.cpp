class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
        if (root == NULL) return 0;
        int left = TreeDepth(root->left);
        if (left == -1) return -1;
        int right = TreeDepth(root->right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return TreeDepth(pRoot)!=-1;
    }
};