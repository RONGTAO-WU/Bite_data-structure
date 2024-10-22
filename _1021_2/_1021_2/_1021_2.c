#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"



void test()
{
	ST st;
	Init(&st);

	stackpush(&st, 1);
	stackpush(&st, 2);
	stackpush(&st, 3);
	stackpush(&st, 4);
	stackpush(&st, 5);
	stackpush(&st, 60);
	stackpush(&st, 70);
	stackpush(&st, 80);
	stackpush(&st, 90);

	print(&st);

	stackpop(&st);	
	stackpop(&st);
	stackpop(&st);

	print(&st);

	while (stackEmpty(&st))
	{
		printf("%d ", stacktop(&st));
		stackpop(&st);
	}
	printf("\n");

	Destroy(&st);

	printf("%x %d", &st,(&st)->arr);

}

int main()
{

	test();


	return 0;
}







//	20. 有效的括号
//	https://leetcode.cn/problems/valid-parentheses/description/



// typedef struct stack{
//
//     char *arr[100];
//     int size;
//     
// }ST;
//
// void init(ST* st)                              // 初始化
// {
//     st->size = 0;
// }
//
// void stackpop(ST* st)                          // 移除栈顶元素
// {
//     st->size--;
// }
//
// char stacktop(ST* st)                          // 取栈顶元素
// {
//     return st->arr[st->size - 1];
// }
//
// void pust(ST* st,char x)                       // 入栈
// {
//     st->arr[st->size] = x;
//     st->size++;
// }
//
// bool stackEmpty(ST* st)                        // 判断栈是否为空
// {
//     return st->size == 0;
// }
//
//bool isValid(char* s) {
//
//    ST S;
//    init(&S);
//
//    char* ret = s;
//
//    //for (int i = 0; i < strlen(ret); i++)
//    //{
//    //    printf("%d ", ret[i]);
//    //}
//
//    while (*ret)
//    {
//
//        if (*ret == '{' || *ret == '[' || *ret == '(')
//        {
//
//            pust(&S, *ret);                                      // 入栈
//            
//        }
//        else
//        {
//            if (stackEmpty(&S))                                 // 栈为空
//            {
//                return false;
//            }
//                                                                
//            char top = stacktop(&S);                            // 不是左括号取栈顶去比较是否匹配
//
//            if (*ret == '}' && top == '{' || *ret == ']' && top == '[' || *ret == ')' && top == '(')           
//
//                stackpop(&S);
//            else
//                return false;
//
//
//                
//
//        }
//        ret++;
//    }
//    if (stackEmpty(&S))
//        return true;
//    else
//        return false;
//
//}
//
//
//
//int main()
//{
//
//    char s[] = "()[]{}";
//
//    isValid(s);
//
//    return 0;
//}