#include<iostream>
using namespace std;



//	155. ��Сջ
//	https://leetcode.cn/problems/min-stack/description/
//	˼·��������ջһ�������СԪ�أ�һ�����ڱ���

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




//	946. ��֤ջ����
//	https://leetcode.cn/problems/validate-stack-sequences/description/
//	��ͼģ��ʵ��

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
	template<class T,class container>

	class stack
	{
	public:

		void push(const T& x)
		{
			_con.push_back(x);
		}

		bool empty()
		{
			return _con_empty();
		}

		void pop()



	private:
		container _con;
	};
}

int main()
{
	bit::stack<int, vector<int>>;
}