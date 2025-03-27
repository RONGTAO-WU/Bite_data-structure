#include<iostream>
using namespace std;

namespace bit
{
	template<class T, class container>

	class queue
	{
	public:

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& top()
		{
			return _con.front();							// vector��֧��front��������erase(begin()),���Ƽ���ΪҪ�ƶ�����
		}

		const T& front()									// queue�ṩ��ȡ��ͷ��β����
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()const
		{
			return _con.size();
		}

	private:
		container _con;
	};
}

#include<list>

int main()
{
	bit::queue<int, list<int>> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;


	return 0;
}