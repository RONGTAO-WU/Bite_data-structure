#include<iostream>
using namespace std;
#include<list>

namespace bit
{
	template<class T>
	struct list_node
	{
	
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& x = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{ }
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> Self;					// 写个模板用来同时实现普通的和const类型的
		
		node* _node;

		list_iterator(node* node)									// 用一个节点的指针构建一个迭代器？
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};
	

	template<class T>
	class list
	{
		typedef list_node<T> node;
		
	public:

		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);

			newnode->_prev = _head->_prev;
			_head->_prev->_next = newnode;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		
	private:

		node* _head;

	};
}

int main()
{
	bit::list<int> ls;

	ls.push_back(10);
	ls.push_back(20);
	ls.push_back(30);
	ls.push_back(40);
	ls.push_back(50);

	bit::list<int>::iterator it1 = ls.begin();
	while (it1 != ls.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	return 0;
}