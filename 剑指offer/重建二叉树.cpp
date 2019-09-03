
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector pre,vector vin) {
        int vinlen=vin.size();
        if(vinlen==0)
            return NULL;
        vector pre_left, pre_right, vin_left, vin_right;
        //创建根节点，根节点肯定是前序遍历的第一个数
        TreeNode* head = new TreeNode(pre[0]);
        //找到中序遍历根节点所在位置,存放于变量gen中
        int gen=0;
        for(int i=0;i<vinlen;i++){
            if(vin[i]==pre[0]){
                gen=i;
                break;
            }
        }
        //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
        // 左子树
        for(int i = 0; i < gen; i++){
            vin_left.push_back(vin[i]);
            pre_left.push_back(pre[i+1]);//先序第一个为根节点
        }
        // 右子树
        for(int i = gen + 1; i < vinlen; i++){
            vin_right.push_back(vin[i]);
            pre_right.push_back(pre[i]);
        }
        //递归，执行上述步骤，区分子树的左、右子子树，直到叶节点
        head->left = reConstructBinaryTree(pre_left, vin_left);
        head->right = reConstructBinaryTree(pre_right, vin_right);
        return head;
    }
};