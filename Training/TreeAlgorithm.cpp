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
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        convertHelper(pRootOfTree, pre);
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
     
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    {
        if(cur == nullptr) return;
        convertHelper(cur ->left, pre);
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;
        convertHelper(cur ->right, pre);

    }
};


/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)   return NULL;
        if(pNode->right!=NULL){
            pNode=pNode->right;
            while(pNode->left!=NULL){
                pNode=pNode->left;
            }
            return pNode;
        }
        while(pNode->next!=NULL){
            TreeLinkNode* parent=pNode->next;
            if(parent->left==pNode) return parent;
            pNode=parent;
        }
        return NULL;
    }
};

/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)   return NULL;
        if(pNode->right!=NULL){
            pNode=pNode->right;
            while(pNode->left!=NULL){
                pNode=pNode->left;
            }
            return pNode;
        }
        while(pNode->next!=NULL){
            TreeLinkNode* parent=pNode->next;
            if(parent->left==pNode) return parent;
            pNode=parent;
        }
        return NULL;
    }
};

/*
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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


/*
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，
其他行以此类推。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == NULL)   return res;
        stack<TreeNode*> even,odd;
        odd.push(pRoot);
        bool flag=true;
        while(!odd.empty()||!even.empty()){
            vector<int> temp;
            if(flag)
            {
                while(!odd.empty()){
                TreeNode* p=odd.top();
                odd.pop();
                temp.push_back(p->val);
                if(p->left)
                    even.push(p->left);
                if(p->right)
                    even.push(p->right);
                }
                flag=false;
            }
            else
            {
                while(!even.empty()){
                TreeNode* p=even.top();
                even.pop();
                temp.push_back(p->val);
                if(p->right)
                    odd.push(p->right);
                if(p->left)
                    odd.push(p->left);
                }
                flag=true;
            }
            res.push_back(temp);
        }
    
        return res;
    }
};

/*
非递归遍历二叉树
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution{
public:
    void inorder(TreeNode *root)
    {
        if(root==NULL)  return NULL;
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(!s.empty()||p){
            while(p){
                s.push(p);
                p=p->left;
            }
            if(!s.empty()){
                p=s.top();
                s.pop();
                cout <<p->val<<endl;
                p=p->right;
            }
        }
    }

    void preorder(TreeNode *root)
    {
        if(root==NULL)  return NULL;
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(!s.empty()||p){
            while(p){
                cout <<p->val<<endl;
                s.push(p);
                p=p->left;
            }
            if(!s.empty()){
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
    }
    //后序遍历的时候要设置一个指向前面的走过节点的指针
    void postorder(TreeNode *root)
    {
        if(root==NULL)  return NULL;
        stack<TreeNode*> s;
        TreeNode* p=root;
        TreeNode* plast=NULL;

        while(p){
            s.push(p);
            p=p->left;
        }
        while(!s.empty()){
            p=s.top();
            s.pop();
            if(p->right== NULL || plast==p->right){
                cout<<p->val;
                plast=p;
            }
            else{
                s.push(p);
                p=p->right;
                while(p){
                    s.push(p);
                    p=p->left;
                }
            }
        }
        return;
    }
};

/*
* 树的性质运算
* 求树的高度
* 求树的节点个数
* 求树的叶节点个数
* 树的复制
*/

class Solution{
public:
    int Depth(TreeNode* root)
    {
        if(root == NULL)    return 0;
        int m=Depth(root->left);
        int n=Depth(root->right);
        return m>n?m+1:n+1;
    }

    int NodeCount(TreeNode *root)
    {
        if(root == NULL)    return 0;
        return NodeCount(root->left)+NodeCount(root->right)+1;
    }

    int leafCount(TreeNode *root)
    {
        if(root == NULL)    return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return leafCount(root->left)+leafCount(root->right);
    }

    TreeNode* copyTree(TreeNode*root, TreeNode &newTree)
    {
        if(root == NULL) return NULL;
        newTree=new TreeNode(0);
        newTree->val=root->val;
        copy(root->left,root->right);
        copy(root->right,root->left);
    }
};