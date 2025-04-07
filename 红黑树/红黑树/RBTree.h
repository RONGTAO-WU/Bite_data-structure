#pragma once

#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class k, class v>
class RBTreeNode
{
public:
	pair<k,v> kv;
	RBTreeNode<k,v>* left;
	RBTreeNode<k,v>* right;
	RBTreeNode<k,v>* parent;
	Colour _col;

	RBTreeNode(const pair<k,v>& kv)
		:kv(kv)
		,left(nullptr)
		,right(nullptr)
		,parent(nullptr)
	{ }
};


template<class k, class v>
class RBTree
{
	typedef RBTreeNode<k, v> Node;
public:

	bool Insert(const pair<k, v>& kv)
	{
		if (root == nullptr)
		{
			root = new Node(kv);
			root->_col = BLACK;															// 根节点必为黑
			return true;
		}

		Node* parent = nullptr;
		Node* cur = root;

		while (cur)
		{
			if (kv.first > cur->kv.first)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (kv.first < cur->kv.first)
			{
				parent = cur;
				cur = cur->left;
			}
			else
				return false;
		}

		cur = new Node(kv);
		cur->_col = RED;																// 插入红的不一定破坏规则，先插入红的
		if (parent->kv.first > cur->kv.first)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;


		//	变色！！！！！
		//	新增标识节点：插入节点的父亲节点(parent)，插入节点父亲的父亲为爷爷节点(grandfather)，父亲的兄弟节点为叔叔节点(uncle)
		//	插入节点为红色(黑色破环规则且不好控制)，若父亲节点为黑色，正常结束。父亲节点为红色，爷爷节点必为黑色，此三节点颜色为固定情况需要变色
		//	关键点为叔叔节点，分三种情况，叔叔节点为红色，叔叔节点为黑色，叔叔节点不存在
		//	叔叔为红色时，直接变色，保持黑色节点平衡要把爷爷节点变红色然后继续向上调整
		//	叔叔不存在时，说明cur必为新插入节点，若cur由爷爷节点变色而来，那么当前分支的黑色节点将比另一分支的多，这棵树本身存在问题。
		//	这种情况需要旋转+变色
		//	


		while (parent && parent->_col == RED)											// 父亲存在且颜色为红色正常循环						
		{

			Node* grandfather = parent->parent;											// 爷爷节点

			if (parent == grandfather->left)										
			{	
				//	父亲节点在爷爷节点左侧
				//			g
				//		p		u
				//	


				Node* uncle = grandfather->right;

				//	叔叔节点存在且颜色为红色

				if (uncle && uncle->_col == RED)									
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;												// 开始变色，父亲，叔叔变黑色，爷爷变红色
					grandfather->_col = RED;

					cur = grandfather;													// 将爷爷节点当作新插入节点，继续向上调整
					parent = cur->parent;												// 更新父亲节点重新循环
				}
				else 
				{
				//	叔叔节点不存在或存在且为黑色
				//	分情况讨论这里大条件已经确定父亲节点位于爷爷的左侧
				//			g								g
				//		p		u			或			p		u						// u可以不存在
				//	c										c

				//	可以看出左边这种情况需要右旋，右边这种情况需要以c为轴左旋变成左边这种情况再以p为轴右旋
				//	因为或存在u为黑色，贸然变色会出现黑色节点不平衡问题
					
					if (cur == parent->left)											// 判断c的位置
					{
						//			g							p
						//		p		u		->			c		g
						//	c											u

						RotateR(parent);												// 右旋+变色
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g							g							c
						//	p		u		->			c		u		->			p		g
						//		c					p											u

						RotateL(parent);												// 先左旋再右旋+变色
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}


					break;

				}
			}
			else
			{
				//	这里就是父亲节点在爷爷节点的右侧
				//			g
				//		u		p
				//

				//	跟上面一样先判断叔叔节点存在且为红色

				Node* uncle = grandfather->left;

				if (uncle && uncle->_col == RED)										// 简单变色同上
				{
					uncle->_col = BLACK;
					parent->_col = BLACK;
					grandfather->_col = RED;
					
					cur = grandfather;
					parent = cur->parent;
				}
				else
				{
				//	叔叔节点不存在或存在且为黑色，分情况讨论c在左侧和c在右侧的情况
				//			g							g
				//		u		p		或			u		p
				//			c									c

					if (cur == parent->left)
					{
						//		g							g								c
						//	u		p		->			u		c			->			g		p
						//		c									p				u
						//

						RotateR(parent);												// 先右旋再左旋+变色
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g								p
						//	u		p			->			g		c
						//				c				u
						//

						RotateL(grandfather);												// 左旋+变色
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;

				}
			}
		}


		root->_col = BLACK; 
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subL = parent->right;
		Node* subLR = subL->left;

		parent->right = subLR;
		if (subLR)
			subLR->parent = parent;

		Node* pp = parent->parent;
		subL->left = parent;
		parent->parent = subL;

		if (pp == nullptr)
		{
			subL->parent = nullptr;
			root = subL;
		}
		else
		{
			if (pp->left == parent)
			{
				pp->left = subL;
				subL->parent = pp;
			}
			else
			{
				pp->right = subL;
				subL->parent = pp;
			}
		}
	}


	void RotateR(Node* parent)
	{
		Node* subR = parent->left;
		Node* subRL = subR->right;

		parent->left = subRL;
		if (subRL)
			subRL->parent = parent;


		Node* pp = parent->parent;
		subR->right = parent;
		parent->parent = subR;

		if (pp == nullptr)
		{
			subR->parent = nullptr;
			root = subR;
		}
		else
		{
			if (pp->left == parent)
			{
				pp->left = subR;
				subR->parent = pp;
			}
			else
			{
				pp->right = subR;
				subR->parent = pp;
			}
		}
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
		cout << root->kv.first << " ";
		_InOrder(root->right);
	}


private:
	Node* root = nullptr;

};