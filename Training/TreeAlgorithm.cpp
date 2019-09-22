/*
��α���
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
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
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
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
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
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
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
��ʵ��һ����������֮���δ�ӡ��������
����һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ��
�������Դ����ơ�
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
�ǵݹ����������
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
    //���������ʱ��Ҫ����һ��ָ��ǰ����߹��ڵ��ָ��
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
* ������������
* �����ĸ߶�
* �����Ľڵ����
* ������Ҷ�ڵ����
* ���ĸ���
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