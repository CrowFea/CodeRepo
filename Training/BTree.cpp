#include<cstdlib>
#include<queue>

namespace BT {
	template<class T>
	struct Node {
		int n;
		struct Node<T>** child;   //���ӵĵ�ַ
		T* key;    //�ؼ���
		bool leaf;  //�Ƿ�ΪҶ�ӵı��
		Node(int t = 0) { n = t;child = NULL; key = NULL;leaf = true; }
		~Node() { n = 0;child = NULL; key = NULL; }
	};
}

template<class T>
class BTree {
public:
    BTree(int m = 2) { t = m;root = new BT::Node<T>;node_num = 0; }
	~BTree() { PostOrder_Delete(root); }
	BT::Node<T>* B_Tree_Search(const T& elem) { return search(root, elem); }    //����Ԫ��
    void B_Tree_Insert(const T& k) { Insert(root, k); }                         //����Ԫ��k
	void B_Tree_Delete(const T &k);					                            //ɾ��Ԫ��k
	void Print();										                        //�ṹ�����
    int size()const { return node_num; }                                        //����Ԫ�صĸ���

private:
	//�ͷ�����ռ�õĿռ䣬��������������
	void PostOrder_Delete(BT::Node<T>*& cur);  //�������ɾ��

	//���Ҳ���
	BT::Node<T>* search(BT::Node<T>* r, const T& elem);

	//���벿��
    void B_Tree_Split_Child(BT::Node<T>* mRoot, int i);//x��i�����ѱ�
    void Insert(BT::Node<T>* &r, const T& k);//����һ��Ҫ����ָ������ã�������޷����ʵ����������
	void B_Tree_Insert_NonFull(BT::Node<T>* mRoot, const T& k); //����ǿ�Ԫ��

	//ɾ������
	void Merge_Node(BT::Node<T>*& mRoot, int i, BT::Node<T>*& y, BT::Node<T>*& z);  //�Ͳ�x�ĵ�i���ӽ��y�͵�i+1���ӽ��z����ʱy��z��key��������t-1
	T Search_Predecessor(BT::Node<T>* y); //����ǰ��
	T Search_Successor(BT::Node<T>* z);   //���Һ��
	void Shift_To_Left_Child(BT::Node<T>*& mRoot, int i, BT::Node<T>*& y, BT::Node<T>*& z);
	void Shift_To_Right_Child(BT::Node<T>*& mRoot, int i, BT::Node<T>*& y, BT::Node<T>*& z);
	void B_Tree_Delete_NoNone(BT::Node<T>* mRoot, const T &k);//ɾ���ڲ����x��k

	//��������
	BT::Node<T>* root;	//�����
	int t;              //������Ĭ����2
    int node_num;       //������
};

template<class T>
BT::Node<T>* BTree<T>::search(BT::Node<T>* mRoot, const T& k) {
	int i = 0;
	while (i<mRoot->n&&k>mRoot->key[i]) {
		++i;
	}
	if (i < mRoot->n&&k == mRoot->key[i]) {   //�ҵ��ˣ����ص�ַ
		return mRoot;
	}
	else if (mRoot->leaf) {        //δ�ҵ������ؿ�
		return NULL;
	}
	else {
		return search(mRoot->child[i], k);   //β�ݹ�����²���
	}
}

template<class T>
void BTree<T>::B_Tree_Split_Child(BT::Node<T>* mRoot, int i) { //i��������±�
	BT::Node<T>* y = mRoot->child[i];
	BT::Node<T>*L, *R;   //L R�����ѱ������Ƭ��
	L = new BT::Node<T>;
	R = new BT::Node<T>;
	L->n = R->n = t - 1;
	L->key = new T[t - 1];
	R->key = new T[t - 1];
	L->leaf = R->leaf = mRoot->child[i]->leaf;  //�����˸��ĺ��ӵ�����
	//���Ƽ�ֵ
	for (int j = 0;j <= t - 2;++j) {
		L->key[j] = y->key[j];
		R->key[j] = y->key[j + t];
	}
	if (!y->leaf) {
		L->child = new BT::Node<T>*[t];
		R->child = new BT::Node<T>*[t];
		for (int j = 0;j < t;++j) {
			L->child[j] = y->child[j];
			R->child[j] = y->child[j + t];
		}
	}
	//����x
	mRoot->key = (T*)realloc(mRoot->key, (mRoot->n + 1) * sizeof(T));
	mRoot->child = (BT::Node<T>**)realloc(mRoot->child, (mRoot->n + 2) * sizeof(BT::Node<T>*));
	for (int j = mRoot->n - 1;j >= i;--j) { //��ֵ����һλ
		mRoot->key[j + 1] = mRoot->key[j];
	}
	mRoot->key[i] = y->key[t - 1];
	for (int j = mRoot->n;j >= i + 1;--j) {
		mRoot->child[j + 1] = mRoot->child[j];
	}
	mRoot->child[i] = L;
	mRoot->child[i + 1] = R;
	mRoot->n++;
	//����ԭ���Ŀռ�
	delete[] y->child;
	delete[] y->key;
	delete y;
}

template<class T>
void BTree<T>::Insert(BT::Node<T>* &r, const T& k) {
	if (B_Tree_Search(k)) {
		return;
	}
	else if (r != NULL && r->n == 2 * t - 1) {
		BT::Node<T>* s = new BT::Node<T>;
		s->leaf = false;
		s->child = new BT::Node<T>*[1];
		s->child[0] = r;
		r = s;
		s->n = 0;
		B_Tree_Split_Child(s, 0);
		B_Tree_Insert_NonFull(s, k);
	}
	else {
		B_Tree_Insert_NonFull(r, k);
	}
    node_num++;  //����������
}

template<class T>
void BTree<T>::B_Tree_Insert_NonFull(BT::Node<T>* mRoot, const T& k) {
	int i = mRoot->n - 1;
	if (mRoot->leaf) {  //Ҷ�ӽ��ֱ�Ӳ���
		mRoot->key = (T*)realloc(mRoot->key, (mRoot->n + 1) * sizeof(T));
		while (i >= 0 && k < mRoot->key[i]) {
			mRoot->key[i + 1] = mRoot->key[i];
			--i;
		}
		mRoot->key[i + 1] = k;
		++mRoot->n;
	}
	else {
		while (i >= 0 && k < mRoot->key[i]) {
			--i;
		}
		++i;
		if (mRoot->child[i]->n == 2 * t - 1) {
			B_Tree_Split_Child(mRoot, i);
			if (k > mRoot->key[i]) {
				++i;
			}
		}
		B_Tree_Insert_NonFull(mRoot->child[i], k);  //β�ݹ�
	}

}

template<class T>
void BTree<T>::Merge_Node(BT::Node<T>*& mRoot, int i, BT::Node<T>*& y, BT::Node<T>*& z) {
	y->key = (T*)realloc(y->key, (2 * t - 1) * sizeof(T));
	for (int j = 0;j < t - 1;++j) {
		y->key[t + j] = z->key[j];
	}
	//����Ҷ�ӽ�������£�����Ҫ���ƺ���
	if (!y->leaf) {
		y->child = (BT::Node<T>**)realloc(y->child, 2 * t * sizeof(BT::Node<T>**));
		for (int j = 0;j < t;++j) {
			y->child[t + j] = z->child[j];
		}
	}
	y->key[t - 1] = mRoot->key[i];  //�ƶ�x�Ľ�㲹�䵽y
	y->n = 2 * t - 1;
	//ɾ��x�����ƹؼ���
	for (int j = i;j < mRoot->n - 1;++j) {
		mRoot->key[j] = mRoot->key[j + 1];
	}
	mRoot->key = (T*)realloc(mRoot->key, (mRoot->n - 1) * sizeof(T));
	//ɾ��ԭ��ָ��z��ָ��
	for (int j = i + 1;j <= mRoot->n - 1;++j) {
		mRoot->child[j] = mRoot->child[j + 1];
	}
	mRoot->child = (BT::Node<T>**)realloc(mRoot->child, (mRoot->n) * sizeof(BT::Node<T>**));
	mRoot->child[i] = y;
	--mRoot->n;
	//�ͷŵ����z
	delete[] z->key;
	delete[] z->child;
	delete z;
	z = NULL;
}

template<class T>
T BTree<T>::Search_Predecessor(BT::Node<T>* y) {
	BT::Node<T>* mRoot = y;//->child[y->n];
	while (!mRoot->leaf) {
		mRoot = mRoot->child[mRoot->n];
	}
	return mRoot->key[mRoot->n - 1];
}

template<class T>
T BTree<T>::Search_Successor(BT::Node<T>* z) {
	BT::Node<T>* mRoot = z;//->child[0];
	while (!mRoot->leaf) {
		mRoot = mRoot->child[0];
	}
	return mRoot->key[0];
}

template<class T>
void BTree<T>::Shift_To_Left_Child(BT::Node<T>*& mRoot, int i, BT::Node<T>*& y, BT::Node<T>*& z) {
	if (y == NULL) {  //��ֹ���ֿ�ָ��
		y = new BT::Node<T>;
	}
	++y->n;
	//���Ƽ�ֵ
	y->key = (T*)realloc(y->key, y->n * sizeof(T));
	y->key[y->n - 1] = mRoot->key[i];
	mRoot->key[i] = z->key[0];
	for (int j = 0;j < z->n - 1;++j) {
		z->key[j] = z->key[j + 1];
	}
	//��Ҷ�ӽ�������¸��ƺ���
	if (!z->leaf) {
		y->child = (BT::Node<T>**)realloc(y->child, (y->n + 1) * sizeof(BT::Node<T>*));
		y->child[y->n] = z->child[0];
		for (int j = 0;j < z->n;++j) {
			z->child[j] = z->child[j + 1];
		}
		z->child = (BT::Node<T>**)realloc(z->child, z->n * sizeof(BT::Node<T>*));
	}
	--z->n;
	z->key = (T*)realloc(z->key, z->n * sizeof(T));
}

template<class T>
void BTree<T>::Shift_To_Right_Child(BT::Node<T>*& mRoot, int i, BT::Node<T>*& y, BT::Node<T>*& z) {
	if (z == NULL) { //��ֹ���ֿ�ָ��
		z = new BT::Node<T>;
	}
	++z->n;
	//���Ƽ�ֵ
	z->key = (T*)realloc(z->key, z->n * sizeof(T));
	for (int j = z->n - 1;j > 0;--j) {
		z->key[j] = z->key[j - 1];
	}
	z->key[0] = mRoot->key[i];
	mRoot->key[i] = y->key[y->n - 1];
	//��Ҷ�ӽ�������¸��ƺ���
	if (!z->leaf) {
		z->child = (BT::Node<T>**)realloc(z->child, (z->n + 1) * sizeof(BT::Node<T>*));
		for (int j = 0;j < z->n;++j) {
			z->child[j + 1] = z->child[j];
		}
		z->child[0] = y->child[y->n];
		y->child = (BT::Node<T>**)realloc(y->child, y->n * sizeof(BT::Node<T>*));
	}
	--y->n;
	y->key = (T*)realloc(y->key, y->n * sizeof(T));
}

template<class T>
void BTree<T>::B_Tree_Delete_NoNone(BT::Node<T>* mRoot, const T &k) {
	//�����ᵽ�ĸ������ȫ�������㷨����
	if (mRoot->leaf) {   //���1
		int i = 0;
		while (i<mRoot->n&&k>mRoot->key[i]) {
			++i;
		}
		for (int j = i + 1;j < mRoot->n;++j) {
			mRoot->key[j - 1] = mRoot->key[j];
		}
		--mRoot->n;
		mRoot->key = (T*)realloc(mRoot->key, mRoot->n * sizeof(T));
	}
	else {
		int i = 0;
		while (i<mRoot->n&&k>mRoot->key[i]) {
			++i;
		}
		BT::Node<T> *y = mRoot->child[i], *z = NULL;
		if (i < mRoot->n) {
			z = mRoot->child[i + 1];
		}
		if (k == mRoot->key[i]) { //���2
			if (y->n > t - 1) { //���2a
				T k1 = Search_Predecessor(y);
				B_Tree_Delete_NoNone(y, k1);
				mRoot->key[i] = k1;
			}
			else if (z->n > t - 1) { //���2b
				T k1 = Search_Successor(z);
				B_Tree_Delete_NoNone(z, k1);
				mRoot->key[i] = k1;
			}
			else {  //���2c
				Merge_Node(mRoot, i, y, z);
				B_Tree_Delete_NoNone(y, k);
			}
		}
		else { //���3
			BT::Node<T>* p = NULL;
			if (i > 0) {
				p = mRoot->child[i - 1];
			}
			if (y->n == t - 1) {
				if (i > 0 && p->n > t - 1) {  //���3a
					Shift_To_Right_Child(mRoot, i - 1, p, y);
				}
                else if (i<mRoot->n&&z->n>t - 1) { //���3a
					Shift_To_Left_Child(mRoot, i, y, z);
				}
				else if (i > 0) { //���3b
					Merge_Node(mRoot, i - 1, p, y);  //�������ϲ�
					y = p;
				}
				else {          //���3b
					Merge_Node(mRoot, i, y, z);      //���Ҳ�ϲ�
				}
			}
			B_Tree_Delete_NoNone(y, k);
		}
	}
}
 
template<class T>
void BTree<T>::B_Tree_Delete(const T &k) {
	BT::Node<T>* r = root;
	if (root->n == 1 && root->child == NULL) {  //ɾ�����һ��Ԫ��
		delete[] root->key;
		delete root;
		root = NULL;
	}
	else if (root->n == 1){  //ѹ�����ڵ�
		BT::Node<T> *y = root->child[0], *z = root->child[1];
		if (y->n == z->n&&y->n == t - 1) {
			Merge_Node(root, 0, y, z);
			root = y;
			delete[] r->child;
			delete[] r->key;
			delete r;
			B_Tree_Delete_NoNone(y, k);
		}
		else {
			B_Tree_Delete_NoNone(root, k);
		}
	}
	else {
		B_Tree_Delete_NoNone(r, k);
	}
    --node_num;  //����������һ��
}

template<class T>
void BTree<T>::Print() {
    BT::Node<T> *last = root;//last��ʾ��ǰ������ҽ��
	BT::Node<T>* p = root;
    std::queue<BT::Node<T>*>Q;
	if (p) {
		Q.push(p);
	}
	while (!Q.empty()) {
		BT::Node<T>* tmp = Q.front();
		Q.pop();
		if (!tmp->leaf) {
            std::cout << "|";
		}
        std::cout << "(";
		for (int i = 0;i < tmp->n;++i) {
            std::cout << tmp->key[i];
			if (tmp->child&&i != tmp->n - 1) {
                std::cout << "|";
			}
		}
        std::cout << ")";
		if (!tmp->leaf) {   //����Ҷ�ӽ����к���
            std::cout << "|";
			for (int i = 0;i < tmp->n + 1;++i) {
				Q.push(tmp->child[i]);
			}
		}
		if (!last->leaf&&tmp == last) {
            std::cout << std::endl;
			last = last->child[last->n];
		}
		
	}
    std::cout << std::endl;
}

template<class T>
void BTree<T>::PostOrder_Delete(BT::Node<T>*& cur) {
    if (cur->leaf) {  //ֱ��ɾ��Ҷ�ӽ��
		delete[] cur->key;
		delete cur;
		cur = NULL;
	}
    else { //�ݹ��ɾ��ÿ������
		for (int i = 0;i < cur->n + 1;++i) {
			PostOrder_Delete(cur->child[i]);
		}
		delete[] cur->key;
		delete cur;
		cur = NULL;
	}
}

