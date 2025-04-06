//#include<iostream>
//using namespace std;
//
//template<class K>
//class SBNode
//{
//public:
//	K _key;
//	SBNode<K>* _left;
//	SBNode<K>* _right;
//
//	SBNode(const K& key)
//	{
//		_key = key;
//		_left = nullptr;
//		_right = nullptr;
//	}
//};
//
//template<class K>
//class Tree
//{
//	typedef SBNode<K> Node;
//
//public:
//	bool insert(const K& _key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(_key);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//
//		while (cur)
//		{
//			if (cur->_key < _key)									// key是插入的数据，与这颗树中的节点值比较
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > _key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//				return false;
//
//		}
//
//		cur = new Node(_key);
//
//		if (parent->_key > _key)
//			parent->_left = cur;
//		else
//			parent->_right = cur;
//
//		return true;
//
//	}
//
//
//
//
//	void _print()
//	{
//		print(_root);
//		cout << endl;
//	}
//
//	void print(Node* root)
//	{
//		if (root == nullptr)
//			return;
//
//		print(root->_left);
//		cout << root->_key << " ";
//		print(root->_right);
//
//	}
//
//
//
//	bool Find(const K& key)
//	{
//
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key == key)
//				return true;
//		}
//
//		return false;
//
//	}
//
//
//	bool esert(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//
//		while (cur)
//		{
//			if (cur->_key < key)									
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				// 等于相当于找到节点位置了
//				// 开始删除，删除一共4种情况，左右节点都为空，左节点为空，右节点为空，左右节点都不为空
//				if (cur->_left == nullptr)						// 左孩子为空
//				{
//					if (cur == _root)
//					{
//						_root = cur->_right;					// 测试发现如果删除根节点要进行一个换根的操作 ！！！
//					}
//					else
//					{
//						if (parent->_left == cur)				// 判断删除位置与父亲位置的链接关系
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//						
//					}
//					delete cur;									// 别忘了释放空间
//				}
//				else if(cur->_right == nullptr)					// 右孩子为空，下面同上
//				{
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//					delete cur;
//				}
//				else
//				{
//					// 左右节点都不为空，用替换法替换删除
//					// 找右子树的最小节点(最左节点)替代					？？？？？？？？？？？？？？？？？
//					Node* replaceParent = cur;
//					Node* replace = cur->_right;
//					while (replace->_left)
//					{
//						replaceParent = replace;
//						replace = replace->_left;
//					}
//
//					swap(cur->_key, replace->_key);
//
//					if (replaceParent->_left == replace)
//						replaceParent->_left = replace->_right;
//					else
//						replaceParent->_right = replace->_right;
//
//					delete replace;
//				}
//
//				return true;
//			}
//				
//		}
//
//		return false;
//	}
//	
//private:
//	Node* _root = nullptr;
//};
//
//
//int main()
//{
//	int arr[] = { 8,6,91,15,284,315,20,3,4,14,8 };
//
//	Tree<int> t;
//
//	for (auto e : arr)
//	{
//		t.insert(e);													// 构建一棵树然后一个一个插入
//	}
//
//	t._print();															// 类中套用调用私有成员变量
//	t.insert(1000);
//	t._print();
//
//	cout << t.Find(999) << endl;
//
//	t.esert(315);
//	t._print();
//
//	t.esert(8);
//	t._print();
//
//	return 0;
//}
//
//
//
//
//#include <iostream>
//#include <queue>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//
//    // 存储每个元素所属的组
//    unordered_map<int, int> group;
//    for (int i = 0; i < t; ++i) {
//        int num;
//        cin >> num;
//        for (int j = 0; j < num; ++j) {
//            int element;
//            cin >> element;
//            group[element] = i;
//        }
//    }
//
//    // 存储每个组的队列
//    vector<queue<int>> groupQueues(t);
//    // 存储组的顺序
//    queue<int> groupOrder;
//
//    string command;
//    while (cin >> command) {
//        if (command == "STOP") {
//            break;
//        } else if (command == "ENQUEUE") {
//            int element;
//            cin >> element;
//            int groupIndex = group[element];
//            if (groupQueues[groupIndex].empty()) {
//                groupOrder.push(groupIndex);
//            }
//            groupQueues[groupIndex].push(element);
//        } else if (command == "DEQUEUE") {
//            if (!groupOrder.empty()) {
//                int frontGroup = groupOrder.front();
//                cout << groupQueues[frontGroup].front() << endl;
//                groupQueues[frontGroup].pop();
//                if (groupQueues[frontGroup].empty()) {
//                    groupOrder.pop();
//                }
//            }
//        }
//    }
//
//    return 0;
//}    


//#include <iostream>
//#include <queue>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//
//    // 存储每个元素所属的组
//    unordered_map<int, int> group;
//    for (int i = 0; i < t; ++i) {
//        int num;
//        cin >> num;
//        for (int j = 0; j < num; ++j) {
//            int element;
//            cin >> element;
//            group[element] = i;
//        }
//    }
//
//    // 存储每个组的队列
//    vector<queue<int>> groupQueues(t);
//    // 存储组的顺序
//    queue<int> groupOrder;
//
//    string command;
//    while (cin >> command) {
//        if (command == "STOP") {
//            break;
//        }
//        else if (command == "ENQUEUE") {
//            int element;
//            cin >> element;
//            int groupIndex = group[element];
//            if (groupQueues[groupIndex].empty()) {
//                groupOrder.push(groupIndex);
//            }
//            groupQueues[groupIndex].push(element);
//        }
//        else if (command == "DEQUEUE") {
//            if (!groupOrder.empty()) {
//                int frontGroup = groupOrder.front();
//                cout << groupQueues[frontGroup].front() << endl;
//                groupQueues[frontGroup].pop();
//                if (groupQueues[frontGroup].empty()) {
//                    groupOrder.pop();
//                }
//            }
//        }
//    }
//
//    return 0;
//}



#include<iostream>
using namespace std;
#include<queue>

int main()
{
	int t;
	cin >> t;

	int n, k;
	queue<int> q1;

	while (t--)
	{
		cin >> n >> k;

		for (int i = 1; i <= n; i++)
		{
			q1.push(i);
		}

		bool first = true;
		while (!q1.empty())
		{
			for (int i = 1; i < k; i++)
			{
				q1.push(q1.front());
				q1.pop();
			}
			if (!first) 
				cout << " ";
			cout << q1.front();
			q1.pop();
			first = false;
		}
		cout << endl;

	}


	return 0;
}