#include<iostream>
using namespace std;

//namespace bit
//{
//	template<class T, class container >
//
//	class queue
//	{
//	public:
//
//		void push(const T& x)
//		{
//			_con.push_back(x);
//		}
//
//		void pop()
//		{
//			_con.pop_front();
//		}
//
//		const T& top()
//		{
//			return _con.front();							// vector不支持front，可以用erase(begin()),不推荐因为要移动数据
//		}
//
//		const T& front()									// queue提供了取队头队尾数据
//		{
//			return _con.front();
//		}
//
//		const T& back()
//		{
//			return _con.back();
//		}
//
//		bool empty()
//		{
//			return _con.empty();
//		}
//
//		size_t size()const
//		{
//			return _con.size();
//		}
//
//	private:
//		container _con;
//	};
//}
//
//#include<list>
//
//int main()
//{
//	bit::queue<int, list<int>> q;
//
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//
//	while (!q.empty())
//	{
//		cout << q.top() << " ";
//		q.pop();
//	}
//	cout << endl;
//
//
//	return 0;
//}



#include<vector>


namespace bit
{
	template<class T, class container = vector<T>>

	class priority_queue										// 优先级队列
	{
	public:

		void adjust_up(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}

		}

		void adjust_down(int parent)
		{
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				{
					child++;
				}

				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}

			}
		}

			void push(const T& x)
			{
				_con.push_back(x);
				adjust_up(_con.size() - 1);
			}

			void pop()
			{
				swap(_con[0], _con[_con.size() - 1]);
				_con.pop_back();
				adjust_down(0);
			}

			const T& top()
			{
				return _con[0];
			}

			size_t size()
			{
				return _con.size();
			}

			bool empty()
			{
				return _con.empty();
			}

		private:
			container _con;


		

	};
}



int main()
{
	bit::priority_queue<int> mypq;

	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);
	
	while (!mypq.empty())
	{
		cout << mypq.top() << " ";
		mypq.pop();
	}
	cout << endl;


	return 0;
}