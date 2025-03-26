#include<iostream>
using namespace std;

#include<vector>

//int main()
//{
//	vector<int> v1;
//	vector<int> v2(10,1);
//	vector<int> v3 = { 10,20,30,40,50 };			// 三种构造方式
//
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//
//	for (size_t i = 0; i < v2.size(); i++)			// 下标+[]
//		cout << v2[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator t1 = v1.begin();			// 迭代器
//	while (t1 != v1.end())
//		cout << *t1++ << " ";
//	cout << endl;
//}


//	136. 只出现一次的数字
//	https://leetcode.cn/problems/single-number/description/

//	思路：用异或的方法解决，题目说了其余元素均出现两次，遍历整个顺序表找出唯一被异或的那个元素


//	118. 杨辉三角
//	https://leetcode.cn/problems/pascals-triangle/description/

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//
//        vector<vector<int>>vv(numRows);
//        for (int i = 0; i < numRows; i++)                // 构建一个杨辉三角
//        {
//            vv[i].resize(i + 1, 1);                     // 初始化全为1
//        }
//
//        for (int i = 2; i < vv.size(); i++)              // 遍历第一层
//        {
//            for (int j = 1; j < vv[i].size() - 1; j++)      // 遍历第二层，只需要访问中间元素
//            {
//                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//            }
//        }
//
//        return vv;
//    }
//};


//	26. 删除有序数组中的重复项
//	https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//
//        if (nums.size() == 0)                    // 特殊情况额外处理
//            return 0;
//
//        int sour = 1;                        // 双指针，dest用来遍历，sour用来覆盖数据
//        int dest = 1;
//
//        for (int i = 0; i < nums.size() - 1; i++)   // 因为是两两比较，所以遍历次数少一次
//        {
//            if (nums[dest] != nums[dest - 1])   // 前一个不等于后一个时
//            {
//                nums[sour] = nums[dest];     // 题目说了是递增数列这里比较是从第二个元素开始的    
//                sour++;
//            }
//            dest++;
//
//        }
//        return sour;
//
//    }
//};




// vector的底层实现


#include<assert.h>

namespace bit
{

	template<class T>

	class vector 
	{

	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		
		iterator begin()												// 迭代器
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const										// 用于const迭代器
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		T& operator[](size_t i)											// 支持下标范围
		{
			return _start[i];
		}


		vector()														// 默认构造
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		//v2(v1)
		vector(const vector<T>& v)										// 拷贝构造
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		vector(size_t n, const T& val = T())									// n个元素初始化
		{
			resize(n, val);
		}


		//v3 = v1
		//vector<T>& operator =(const vector<T>& v)						// 赋值构造的一种复杂写法
		//{
		//	if (this != &v)
		//	{
		//		delete[]_start;
		//		_start = _finish = _end_of_storage = nullptr;
		//		reserve(v.size());
		//		for (auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//		
		//	}	

		//	return *this;
		//}

		//v3 = v1
		vector<T>& operator =(vector<T> v)								// v3想跟v1有一样的空间一样的值
																		// 直接让v1传值传参，交换一份v1的数据即可
		{
			swap(v);
			return *this;
		}

		void swap(vector<T> v)
		{
			std::swap(_start,v._start);
			std::swap(_finish,v._finish);
			std::swap(_end_of_storage,v._end_of_storage);
		}

		~vector()
		{
			delete[]_start;												// 释放首地址
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		void push_back(const T& x)										// 尾插
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 :capacity() * 2);
			}

			*_finish = x;												
			_finish++;
		}

		void pop_back()													// 尾删
		{
			assert(_finish > _start);
			_finish--;
		}


		//	扩容会导致迭代器失效，失效需要更新在使用，要记录pos的相对于起点的位置

		void insert(iterator pos,const T& x)							// 任意位置插入一个数据
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)				// 判断容量是否够扩容
			{
				size_t len = pos - _start;				// 记录相对位置				
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = len + _start;
			}

			iterator it = _finish-1;

			while (it >= pos)							// pos后的数据向后移动
			{
				*(it + 1) = *it;
				it--;
			}

			*pos = x;
			_finish++;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			iterator it = pos+1;

			while (it >	_finish)
			{
				*(it-1) = *it;
				it++;
			}

			_finish--;
		}

		void resize(size_t n,const T& val = T())
		{
			if (n < size())												// 缩容，有效长度缩小
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);												// 扩容，后面直接填充数据
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void reserve(size_t n)											// 扩容
		{
			if (n > capacity())
			{
				//size_t oldsize = size();								//（最好提前记录下size）
				T* tmp = new T[n];
	//			memcpy(tmp, _start, sizeof(T) * size());				//	memcpy是浅拷贝，自定义类型用可能会引发一些问题

				for (size_t i = 0; i < size(); i++)						//	处理浅拷贝释放同一块空间的问题，直接赋值
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
				_finish = tmp + size();									//_start释放掉了用tmp
				_start = tmp;
				//_finish = _start + size();							// 得先更新size
				_end_of_storage = _start + n;
			}
		}


		// 类模板的成员函数也可以是一个函数模板
		 
		/*template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}*/



	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}


int main()
{
	bit::vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);											
																
	v1.push_back(50);
	v1.pop_back();

	for (const int& e : v1)										// 范围for
	{
		std::cout << e << " ";
	}
	std::cout << endl;

	

	v1.insert(v1.begin() + 1, 30);								// 这里如果正好4个大小，扩容会导致<迭代器失效>！！！
																// 扩容会导致begin的位置发生改变，在这之前的begin都会失效
																// 本质是野指针


	bit::vector<int>::iterator t1 = v1.begin();					// 迭代器
	while (t1 != v1.end())
	{
		std::cout << *t1 << " ";
		t1++;
	}
	std::cout << endl;



	v1.erase(v1.begin() + 3);



	for (int i = 0; i < v1.size(); i++)							// 下标+[]
	{
		std::cout << v1[i] << " ";
	}
	std::cout << endl;


	v1.resize(10, 1);



	for (int i = 0; i < v1.size(); i++)							
	{
		std::cout << v1[i] << " ";
	}
	std::cout << endl;


	bit::vector<int> v2(v1);									// 拷贝构造
	bit::vector<int> v3 = v1;									// 赋值构造
	v3.resize(100,1);


	for (int i = 0; i < v2.size(); i++)							
	{
		std::cout << v2[i] << " ";
	}
	std::cout << endl;
	for (int i = 0; i < v3.size(); i++)							
	{
		std::cout << v3[i] << " ";
	}
	std::cout << endl;



	//bit::vector<int> v4(v3.begin() + 2, v3.end() - 2);		// 迭代区间初始化
	//for (int i = 0; i < v4.size(); i++)
	//{
	//	std::cout << v4[i] << " ";
	//}
	//std::cout << endl;



	bit::vector<int> v5(10,2);									// n个数据初始化（需要屏蔽模板，因为跟这里更匹配）
	for (int i = 0; i < v5.size(); i++)
	{
		std::cout << v5[i] << " ";
	}
	std::cout << endl;

}

