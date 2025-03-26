#include<iostream>
using namespace std;

#include<vector>

//int main()
//{
//	vector<int> v1;
//	vector<int> v2(10,1);
//	vector<int> v3 = { 10,20,30,40,50 };			// ���ֹ��췽ʽ
//
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//
//	for (size_t i = 0; i < v2.size(); i++)			// �±�+[]
//		cout << v2[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator t1 = v1.begin();			// ������
//	while (t1 != v1.end())
//		cout << *t1++ << " ";
//	cout << endl;
//}


//	136. ֻ����һ�ε�����
//	https://leetcode.cn/problems/single-number/description/

//	˼·�������ķ����������Ŀ˵������Ԫ�ؾ��������Σ���������˳����ҳ�Ψһ�������Ǹ�Ԫ��


//	118. �������
//	https://leetcode.cn/problems/pascals-triangle/description/

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//
//        vector<vector<int>>vv(numRows);
//        for (int i = 0; i < numRows; i++)                // ����һ���������
//        {
//            vv[i].resize(i + 1, 1);                     // ��ʼ��ȫΪ1
//        }
//
//        for (int i = 2; i < vv.size(); i++)              // ������һ��
//        {
//            for (int j = 1; j < vv[i].size() - 1; j++)      // �����ڶ��㣬ֻ��Ҫ�����м�Ԫ��
//            {
//                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//            }
//        }
//
//        return vv;
//    }
//};


//	26. ɾ�����������е��ظ���
//	https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//
//        if (nums.size() == 0)                    // ����������⴦��
//            return 0;
//
//        int sour = 1;                        // ˫ָ�룬dest����������sour������������
//        int dest = 1;
//
//        for (int i = 0; i < nums.size() - 1; i++)   // ��Ϊ�������Ƚϣ����Ա���������һ��
//        {
//            if (nums[dest] != nums[dest - 1])   // ǰһ�������ں�һ��ʱ
//            {
//                nums[sour] = nums[dest];     // ��Ŀ˵���ǵ�����������Ƚ��Ǵӵڶ���Ԫ�ؿ�ʼ��    
//                sour++;
//            }
//            dest++;
//
//        }
//        return sour;
//
//    }
//};




// vector�ĵײ�ʵ��


#include<assert.h>

namespace bit
{

	template<class T>

	class vector 
	{

	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		
		iterator begin()												// ������
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const										// ����const������
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		T& operator[](size_t i)											// ֧���±귶Χ
		{
			return _start[i];
		}


		vector()														// Ĭ�Ϲ���
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		//v2(v1)
		vector(const vector<T>& v)										// ��������
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		vector(size_t n, const T& val = T())									// n��Ԫ�س�ʼ��
		{
			resize(n, val);
		}


		//v3 = v1
		//vector<T>& operator =(const vector<T>& v)						// ��ֵ�����һ�ָ���д��
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
		vector<T>& operator =(vector<T> v)								// v3���v1��һ���Ŀռ�һ����ֵ
																		// ֱ����v1��ֵ���Σ�����һ��v1�����ݼ���
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
			delete[]_start;												// �ͷ��׵�ַ
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

		void push_back(const T& x)										// β��
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 :capacity() * 2);
			}

			*_finish = x;												
			_finish++;
		}

		void pop_back()													// βɾ
		{
			assert(_finish > _start);
			_finish--;
		}


		//	���ݻᵼ�µ�����ʧЧ��ʧЧ��Ҫ������ʹ�ã�Ҫ��¼pos�����������λ��

		void insert(iterator pos,const T& x)							// ����λ�ò���һ������
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)				// �ж������Ƿ�����
			{
				size_t len = pos - _start;				// ��¼���λ��				
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = len + _start;
			}

			iterator it = _finish-1;

			while (it >= pos)							// pos�����������ƶ�
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
			if (n < size())												// ���ݣ���Ч������С
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);												// ���ݣ�����ֱ���������
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void reserve(size_t n)											// ����
		{
			if (n > capacity())
			{
				//size_t oldsize = size();								//�������ǰ��¼��size��
				T* tmp = new T[n];
	//			memcpy(tmp, _start, sizeof(T) * size());				//	memcpy��ǳ�������Զ��������ÿ��ܻ�����һЩ����

				for (size_t i = 0; i < size(); i++)						//	����ǳ�����ͷ�ͬһ��ռ�����⣬ֱ�Ӹ�ֵ
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
				_finish = tmp + size();									//_start�ͷŵ�����tmp
				_start = tmp;
				//_finish = _start + size();							// ���ȸ���size
				_end_of_storage = _start + n;
			}
		}


		// ��ģ��ĳ�Ա����Ҳ������һ������ģ��
		 
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

	for (const int& e : v1)										// ��Χfor
	{
		std::cout << e << " ";
	}
	std::cout << endl;

	

	v1.insert(v1.begin() + 1, 30);								// �����������4����С�����ݻᵼ��<������ʧЧ>������
																// ���ݻᵼ��begin��λ�÷����ı䣬����֮ǰ��begin����ʧЧ
																// ������Ұָ��


	bit::vector<int>::iterator t1 = v1.begin();					// ������
	while (t1 != v1.end())
	{
		std::cout << *t1 << " ";
		t1++;
	}
	std::cout << endl;



	v1.erase(v1.begin() + 3);



	for (int i = 0; i < v1.size(); i++)							// �±�+[]
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


	bit::vector<int> v2(v1);									// ��������
	bit::vector<int> v3 = v1;									// ��ֵ����
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



	//bit::vector<int> v4(v3.begin() + 2, v3.end() - 2);		// ���������ʼ��
	//for (int i = 0; i < v4.size(); i++)
	//{
	//	std::cout << v4[i] << " ";
	//}
	//std::cout << endl;



	bit::vector<int> v5(10,2);									// n�����ݳ�ʼ������Ҫ����ģ�壬��Ϊ�������ƥ�䣩
	for (int i = 0; i < v5.size(); i++)
	{
		std::cout << v5[i] << " ";
	}
	std::cout << endl;

}

