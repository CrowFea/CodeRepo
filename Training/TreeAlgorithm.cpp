/*
层次遍历
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL)    return res;
        q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front();
            /*如果是从右到左就先把右入栈*/
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            q.pop();
            res.push_back(p)->val;
        }
        return res;
    }
};

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool judge(vector<int> nodes)
    {
        if(nodes.size() <= 1)   return true;
        vector<int> left,right;
        int i,j;
        for(i=0;i<nodes.size()-1;i++){
            if(nodes[i]<nodes[nodes.size()-1]){
                left.push_back(nodes[i]);
            }
            else{
                break;
            }
        }
        if(i==nodes.size()) return false;
        for(int j=i;j<nodes.size()-1;j++){
            if(nodes[j]<nodes[nodes.size()-1]){
                return false;
            }
            right.push_back(nodes[j]);
        }
        return judge(left)&&judge(right);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)  return false;
        return judge(sequence);
    }
};



/*
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
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
    vector<vector<int> > res;
    vector<int> temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)    return res;
        temp.push_back(root->val);
        expectNumber-=root->val;
        if(expectNumber==0 && root->left==NULL && root->right==NULL){
            res.push_back(temp);
        }
        FindPath(root->left,expectNumber);
        FindPath(root->right,expectNumber);
        temp.pop_back();
        return res;
    }
};


/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)   return NULL;
        
    }
};