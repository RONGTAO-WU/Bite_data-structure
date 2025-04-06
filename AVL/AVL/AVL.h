#pragma once

#include<iostream>
using namespace std;


// AVL树结构

template<class K, class V>										//  first 和 second

struct AVLTreeNode
{
	pair<K, V> kv;												// 一个用来存节点数值，一个用来存平衡因子
	AVLTreeNode<K, V>* left;
	AVLTreeNode<K, V>* right;
	AVLTreeNode<K, V>* _parent;									// 指向父亲节点，主要用于更新平衡因子
	int bf;

	AVLTreeNode(const pair<K, V>& kv)
		:kv(kv)
		,left(nullptr)
		,right(nullptr)
		,_parent(nullptr)
		,bf(0)
	{}

};



template<class K,class V>

class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:

	bool Insert(const pair<K, V>& kv)
	{
		if (root == nullptr)									// 如果这是个空树，给它new一个新节点
		{
			root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = root;										// 非空树从根节点开始找位置插入

		while (cur)
		{
			if (cur->kv.first < kv.first)						// 插入的节点大于当前节点往右走
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->kv.first > kv.first)					// 反之往左走
			{
				parent = cur;
				cur = cur->left;
			}
			else
				return false;
		}

		cur = new Node(kv);
		if (parent->kv.first < kv.first)						// 找到位置插入
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}

		cur->_parent = parent;





		while (parent)											// 更新平衡因子,如果有需要调整到根
		{
			if (cur == parent->left)							// 左减右加
				parent->bf--;
			else
				parent->bf++;
			

			//通过平衡因子的值来判断树是否平衡

			if (parent->bf == 0)								// 平衡		
				break;
			else if (parent->bf == -1 || parent->bf == 1)		// 继续向上调整
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->bf == -2 || parent->bf == 2)		// 分情况选择旋转
			{

				if (parent->bf == -2 && cur->bf == -1)			// 右单旋
					RotateR(parent);
				else
				if (parent->bf == 2 && cur->bf == 1)			// 左单旋
					RotateL(parent);
				else
				if (parent->bf == -2 && cur->bf == 1)			// 左右双旋
					RotateLR(parent);
				else
				if (parent->bf == 2 && cur->bf == -1)			// 右左双旋
					RotateRL(parent);

				break;											// 旋转完正常结束

			}
			else
				return false;									// 不等于以上值说明插入前这颗树就已经不平衡了

														
		}

		return true;
	}



	// 右旋 ！！！！！
	void RotateR(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)												// 需要判断这块空间是不是为空
			subLR->_parent = parent;							// 如果不是将它的父亲指针指向新的父亲

		Node* parentparent = parent->_parent;					// parent有可能是整棵树的根，也可能是局部的⼦树
		parent->_parent = subL;									// 如果是整棵树的根，要修改_root
		subL->right = parent;									// 如果是局部的指针要跟上⼀层链接

		if (parentparent == nullptr)							// 说明是root节点
		{
			subL->_parent = nullptr;
			root = subL;										// 更新为最新的root节点
		}
		else
		{														// 不是root要跟上一层链接
			if (parent == parentparent->left)					// 原父亲节点如果是再上层的左子树
			{
				parentparent->left = subL;						// 更新上对下关系
			}
			else
				parentparent->right = subL;

			subL->_parent = parentparent;						// 更新下对上关系

		}

		parent->bf = subL->bf = 0;


	}



	// 左旋 ！！！！！											// 同上，画图理解
	void RotateL(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->_parent = parent;


		Node* pp = parent->_parent;

		subR->left = parent;
		parent->_parent = subR;

		
		if (pp == nullptr)
		{
			subR->_parent = nullptr;
			root = subR;
		}
		else
		{
			if (parent == pp->left)
				pp->left = subR;
			else
				pp->right = subR;

			subR->_parent = pp;
		}

		parent->bf = subR->bf = 0;
	}



	// 左右双旋 ！！！！！										// 单旋的复用，关键在于平衡因子的更新
	void RotateLR(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->bf;										// 记录此时的LR(未来的根节点)的平衡因子

		RotateL(parent->left);									// 先对部分左旋在对整体右旋
		RotateR(parent);				


		if (bf == -1)											// 如果最初是-1，那么这个插入就在它的左节点
																// 最后这部分将分配在subL的右节点，那么分配到parent的左节点那部分就会导致其不平衡
		{
			subLR->bf = 0;
			subL->bf = 0;
			parent->bf = 1;
		}
		else if (bf == 1)
		{
			subLR->bf = 0;
			subL->bf = -1;
			parent->bf = 0;
		}
		else if (bf == 0)										// 一种特殊情况，当subLR区域为空时，即插入节点就是subLR(就三个节点旋转)
		{
			subLR->bf = 0;
			subL->bf = 0;
			parent->bf = 0;
		}
		/*else
			return false;*/
	}



	// 右左双旋 ！！！！！
	void RotateRL(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;
		int bf = subRL->bf;

		RotateR(parent->right);
		RotateL(parent);

		if (bf == -1)
		{
			subRL->bf = 0;
			subR->bf = 1;
			parent->bf = 0;
		}
		else if (bf == 1)
		{
			subRL->bf = 0;
			subR->bf = 0;
			parent->bf = -1;
		}
		else if (bf == 0)
		{
			subRL->bf = 0;
			subR->bf = 0;
			parent->bf = 0;
		}
		/*else
			return false;*/
	}


	void InOrder()
	{
		_InOrder(root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->left);
		cout << root->kv.first<< " ";
		_InOrder(root->right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return -1;
		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(root);
	}

	bool _IsBalanceTree(Node* root)
	{
		// 	空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因⼦：即pRoot左右⼦树的⾼度差

		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);

		int diff = rightHeight - leftHeight;
		// 如果计算出的平衡因⼦与pRoot的平衡因⼦不相等，或者
		// pRoot平衡因⼦的绝对值超过1，则⼀定不是AVL树

		if (abs(diff) >= 2)
		{
			cout << root->kv.first << " " << "高度差异常" << endl;
			return false;
		}

		if (root->bf != diff)
		{
			cout << root->kv.first << " " << "平衡因⼦异常" << endl;
				return false;
		}
		// pRoot的左和右如果都是AVL树，则该树⼀定是AVL树

		return _IsBalanceTree(root->left) && _IsBalanceTree(root->right);


	}

private:
	Node* root = nullptr;

};





