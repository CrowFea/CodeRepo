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