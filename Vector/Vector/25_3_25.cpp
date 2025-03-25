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


namespace bit
{

	template<class T>

	class vector 
	{

	public:
		typedef T* iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		T& operator[](size_t i)
		{
			return _start[i];
		}


		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

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

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 :capacity() * 2);
			}

			*_finish = x;												// 尾插
			_finish++;
		}

		void reserve(size_t n)											// 扩容
		{
			if (n > capacity())
			{
				//size_t oldsize = size();								//（最好提前记录下size）
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;
				_finish = tmp + size();									//_start释放掉了用tmp
				_start = tmp;
				//_finish = _start + size();							// 得先更新size
				_end_of_storage = _start + n;
			}
		}

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

	for (const int& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}