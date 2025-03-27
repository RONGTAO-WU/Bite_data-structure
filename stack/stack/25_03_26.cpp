#include<iostream>
using namespace std;



//	155. 最小栈
//	https://leetcode.cn/problems/min-stack/description/
//	思路：用两个栈一个存放最小元素，一个用于遍历

//class MinStack {
//public:
//    MinStack() {
//
//
//    }
//
//    void push(int val) {
//        s1.push(val);
//        if (s2.empty() || val <= s2.top())
//            s2.push(val);
//    }
//
//    void pop() {
//
//        if (s1.top() == s2.top())
//            s2.pop();
//
//        s1.pop();
//    }
//
//    int top() {
//        return s1.top();
//    }
//
//    int getMin() {
//        return s2.top();
//    }
//
//    stack<int> s1;
//    stack<int> s2;
//};




//	946. 验证栈序列
//	https://leetcode.cn/problems/validate-stack-sequences/description/
//	画图模拟实现

//class Solution {
//public:
//    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//        stack<int> st;
//        int i = 0;
//        for (const int& e : pushed)
//        {
//            st.push(e);
//
//            while (!st.empty() && st.top() == popped[i])
//            {
//                i++;
//                st.pop();
//            }
//        }
//        return st.empty();
//    }
//};


namespace bit
{
	// stack<int,vector<int>>
	// stack<int,list<int>>

	template<class T,class container = vector<T>>

	class stack
	{
	public:

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		bool empty()
		{
			return _con.empty();
		}

		const T& top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}



	private:
		container _con;
	};
}

#include<vector>

int main()
{
	bit::stack<int, vector<int>> st;

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;


	return 0;
}
