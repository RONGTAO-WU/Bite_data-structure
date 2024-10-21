#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"



//void test()
//{
//	ST st;
//	Init(&st);
//
//	stackpush(&st, 1);
//	stackpush(&st, 2);
//	stackpush(&st, 3);
//	stackpush(&st, 4);
//	stackpush(&st, 5);
//	stackpush(&st, 60);
//	stackpush(&st, 70);
//	stackpush(&st, 80);
//	stackpush(&st, 90);
//
//	print(&st);
//
//	stackpop(&st);	
//	stackpop(&st);
//	stackpop(&st);
//
//	print(&st);
//
//	while (stackEmpty(&st))
//	{
//		printf("%d ", stacktop(&st));
//		stackpop(&st);
//	}
//	printf("\n");
//
//	Destroy(&st);
//
//	printf("%x %d", &st,(&st)->arr);
//
//}

//int main()
//{
//
//	test();
//
//
//	return 0;
//}







//	
//	

 typedef struct stack{

     char *arr[100];
     int size;
     
 }ST;

 void init(ST* st)                              // ³õÊ¼»¯
 {
     st->size = 0;
 }

 void stackpop(ST* st)                          // ÒÆ³ýÕ»¶¥ÔªËØ
 {
     st->size--;
 }

 char stacktop(ST* st)                          // È¡Õ»¶¥ÔªËØ
 {
     return st->arr[st->size - 1];
 }

 void pust(ST* st,char x)                       // ÈëÕ»
 {
     st->arr[st->size] = x;
     st->size++;
 }

 bool stackEmpty(ST* st)                        // ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
 {
     return st->size == 0;
 }

bool isValid(char* s) {

    ST S;
    init(&S);

    char* ret = s;

    //for (int i = 0; i < strlen(ret); i++)
    //{
    //    printf("%d ", ret[i]);
    //}

    while (*ret)
    {

        if (*ret == '{' || *ret == '[' || *ret == '(')
        {

            pust(&S, ret);                                      // ÈëÕ»
            
        }
        else
        {
            if (stackEmpty(&S))                                 // Õ»Îª¿Õ
            {
                return false;
            }
                                                                
            char top = stacktop(&S);                            // ²»ÊÇ×óÀ¨ºÅÈ¡Õ»¶¥È¥±È½ÏÊÇ·ñÆ¥Åä

            if (*ret == '{' && top == '}' || *ret == '[' && top == ']' || *ret == '(' && top == ')')           

                stackpop(&S);
            else
                return false;


                

        }
        ret++;
    }
    if (stackEmpty(&S))
        return true;
    else
        return false;

}



int main()
{

    char s[] = "()[]{}";

    isValid(s);

    return 0;
}