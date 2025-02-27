enum RBTColor { RED, BLACK };

template <class T>
class RBTNode {
public:
	RBTColor color;    // 颜色
	T key;            // 关键字(键值)
	RBTNode* left;    // 左孩子
	RBTNode* right;    // 右孩子
	RBTNode* parent; // 父结点

	RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
		key(value), color(c), parent(), left(l), right(r) {}
};

template <class T>
class RBTree {
private:
	RBTNode<T>* mRoot;    // 根结点

public://外部接口
	RBTree();
	~RBTree();

	// 前序遍历"红黑树"
	void preOrder();
	// 中序遍历"红黑树"
	void inOrder();
	// 后序遍历"红黑树"
	void postOrder();

	// (递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* search(T key);
	// (非递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* iterativeSearch(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();

	// 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
	RBTNode<T>* successor(RBTNode<T>* x);
	// 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
	RBTNode<T>* predecessor(RBTNode<T>* x);

	// 将结点(key为节点键值)插入到红黑树中
	void insert(T key);

	// 删除结点(key为节点键值)
	void remove(T key);

	// 销毁红黑树
	void destroy();

	// 打印红黑树
	void print();
private://内部接口
	// 前序遍历"红黑树"
	void preOrder(RBTNode<T>* tree) const;
	// 中序遍历"红黑树"
	void inOrder(RBTNode<T>* tree) const;
	// 后序遍历"红黑树"
	void postOrder(RBTNode<T>* tree) const;

	// (递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	// (非递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的红黑树的最小结点。
	RBTNode<T>* minimum(RBTNode<T>* tree);
	// 查找最大结点：返回tree为根结点的红黑树的最大结点。
	RBTNode<T>* maximum(RBTNode<T>* tree);

	// 左旋
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
	// 右旋
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* y);
	// 插入函数
	void insert(RBTNode<T>*& root, RBTNode<T>* node);
	// 插入修正函数
	void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node);
	// 删除函数
	void remove(RBTNode<T>*& root, RBTNode<T>* node);
	// 删除修正函数
	void removeFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

	// 销毁红黑树
	void destroy(RBTNode<T>*& tree);

	// 打印红黑树
	void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

//================================================================
/*
 * 构造函数与析构函数
 *
 * 
 */
template <class T>
RBTree<T>::RBTree():mRoot(NULL)
{
	mRoot=NULL;
}

template <class T>
RBTree<T>::~RBTree()
{
	destroy();
}

//================================================================
/*
 * 先序、中序、后序遍历
 *
 * 参数说明：
 *     tree 红黑树的根
 * 
 */
//先序遍历
template <class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if(tree==NULL)	return;
	{
		cout<<tree->key<<" ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void RBTree<T>::preOrder() 
{
	preOrder(mRoot);
}
//中序遍历
template <class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
	if(tree==NULL)	return;
	{
		preOrder(tree->left);
		cout<<tree->key<<" ";
		preOrder(tree->right);
	}
}

template <class T>
void RBTree<T>::inOrder() 
{
	inOrder(mRoot);
}
//后序遍历
template <class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if(tree==NULL)	return;
	{
		preOrder(tree->left);
		preOrder(tree->right);
		cout<<tree->key<<" ";
	}
}

template <class T>
void RBTree<T>::preOrder()
{
	postOrder(tree);
}

//================================================================
/*
 * 查找指定key值的节点
 *
 * 参数说明：
 *     x 红黑树的根
 * 	   key 要查找的值
 * 
 */
template <class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
	if(x==NULL || x->key==key)	return x;
	else if(x->key>key)	return search(x->right,key);
	return search(x->right,key);
}

template <class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot,key);
}

//查找指定的值key的节点(非递归实现)
template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	while(x && x->key != key){
		if(x->key < key){
			x=x->right;
		}
		else{
			x=x->left;
		}
	}
	return x;
}

template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot,key);
}

//================================================================
/*
 * 查找最小节点
 *
 * 参数说明：
 *     tree 红黑树的根
 * 
 */
template <class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if(tree==NULL)	return tree;
	while(tree->left!=NULL){
		tree=tree->left;
	}
	return tree;
}

template <class T>
T RBTree<T>::minimum()
{
	RBTNode<T>* p=minimum(mRoot);
	if(p!=NULL){
		return p->key;
	}
	return (T)NULL;//注意这里
}
/*
 * 查找最大节点
 *
 * 参数说明：
 *     tree 红黑树的根
 * 
 */
template <class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if(tree==NULL)	return tree;
	while(tree->right!=NULL){
		tree=tree->right;
	}
	return tree;
}

template <class T>
T RBTree<T>::maximum()
{
	RBTNode<T>* p=maximum(mRoot);
	if(p!=NULL){
		return p->key;
	}
	return (T)NULL;//注意这里
}

//================================================================
/*
 * 查找后继节点
 *
 * 查找节点x的后继节点，即，查找数据值大于该节点的最小节点
 *
 * 参数说明：
 *     x 要查找的基准节点
 * 
 */
template <class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
	if(x->right)	return minimum(x->right); //注意这里
	RBTNode<T>* p=x->parent;
	while(p && x==p->right){
		x=p;
		p=p->parent;
	}
	return p;

}
/*
 * 查找前驱节点
 *
 * 查找节点x的前驱节点，即，查找数据值小于该节点的最大节点
 *
 * 参数说明：
 *     x 要查找的基准节点
 * 
 */
template <class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x)
{
	if(x->left)	return maximum(x->left);
	RBTree<T>* p=x->parent;
	while(p && p->left==x){
		x=p;
		p=p->parent;
	}
	return p;
}

//================================================================
/* 
* 对红黑树的节点(x)进行左旋转
*
* 左旋示意图(对节点x进行左旋)：
*      px                              px
*     /                               /
*    x                               y                
*   /  \      --(左旋)-->           / \                #
*  lx   y                          x  ry     
*     /   \                       /  \
*    ly   ry                     lx  ly  
*
* 参数说明：
*     root 红黑树的根
*     x 对这个节点旋转，实际上跟root没啥关系
*/
template<class T> 
void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->right;
	x->right = y->left;
	if (y->left != NULL)   y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else {
		if (x->parent->left == x) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
	}
	y->left = x;
	x->parent = y;
}
/* 
* 对红黑树的节点(y)进行右旋转
* 
* 右旋示意图(对节点y进行左旋)：
*            py                               py
*           /                                /
*          y                                x                  
*         /  \      --(右旋)-->            /  \                     #
*        x   ry                           lx   y  
*       / \                                   / \                   #
*      lx  rx                                rx  ry
* 
* 参数说明：
*     root 红黑树的根
*     y 对这个节点旋转，实际上跟root没啥关系
*/
template<class T>
void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* y)
{
	RBTNode<T>* x = y->left;

	x->right = y->left;
	if (y->left != NULL)   y->left->parent = x;
	x->parent = y->parent;

	if (y->parent == NULL) {
		root = x;
	}
	else {
		if (y->parent->left == y) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}
	y->parent = x;
	x->right = y;

}

//================================================================
/*
 * 红黑树插入函数
 *
 * 在向红黑树中插入节点
 * 按照正常的二叉排序树对待，最后调用调整函数
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 插入的结点        // 对应《算法导论》中的z
 * 
 */
//内部接口
template <class T>
void insert(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T>* p=root;
    while(p!=NULL){
        if(root->value<p->value){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    node->parent=p;
    if(p!=NULL){
        if(node->value>p->value){
            p->right=node;
        }
        else{
            p->left=node;
        }
    }
    else{
        root=node;//不要忘记
    }

    node->color=RED;
    insertFixUp(root,node);
}
//外部接口
template <class T>
void RBTree<T>::insert(T key)
{
    RBTNode<T>* p=NULL;
    if((p=new RBTNode<T>(key,BLACK,NULL,NULL,NULL)==NULL))
        return;
    insert(mRoot,z);
}
/*
 * 红黑树插入修正函数
 *
 * 在向红黑树中插入节点之后(失去平衡)，再调用该函数；
 * 目的是将它重新塑造成一颗红黑树。
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 插入的结点        // 对应《算法导论》中的z
 * 
 * 比较困难，牢记
 */
template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
    while(rb_parent(node)&&rb_is_red(rb_parent(node))){
        RBTNode<T>* parent=rb_parent(node);
        RBTNode<T>* gparent=rb_parent(parent);
        if(parent==gparent->left){
            RBTNode<T>* uncle=gparent->right;
            //叔存且红
            if(uncle&&rb_is_red(uncle)){
                
                rb_set_red(gparent);
                rb_set_black(parent);
                rb_set_black(uncle);
                node=gparent;
                continue;
            }
            //叔黑，当前右
            else if(node==parent->right){
                leftRotate(root,parent);
                RBTNode<T>* tmp=parent;
                parent=node;
                node=tmp;
            }
            //叔黑，当前左
            rb_set_red(gparent);
            rb_set_black(parent);
            rightRotate(root,gparent);
        }
        else{
            RBTNode<T>* uncle=gparent->left;
            if(uncle&&rb_is_red(uncle)){
                rb_set_red(gparent);
                rb_set_black(parent);
                rb_set_black(uncle);
                node=gparent;
                continue;
            }
            else if(node==parent->left){
                RBTNode<T>* tmp;
                rightRotate(root,parent);
                tmp=parent;
                parent=node;
                node=tmp;
            }
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root,gparent);
        }
    }
    rb_set_black(root);
}

//================================================================
//删除操作
