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

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 :capacity() * 2);
			}

			*_finish = x;												// β��
			_finish++;
		}

		void reserve(size_t n)											// ����
		{
			if (n > capacity())
			{
				//size_t oldsize = size();								//�������ǰ��¼��size��
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;
				_finish = tmp + size();									//_start�ͷŵ�����tmp
				_start = tmp;
				//_finish = _start + size();							// ���ȸ���size
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