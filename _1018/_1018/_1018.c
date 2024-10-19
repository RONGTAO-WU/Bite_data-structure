#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>




//  203. 移除链表元素
//  https://leetcode.cn/problems/remove-linked-list-elements/description/



//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//
//    struct ListNode* newhead, * newtail;
//    newhead = NULL;
//    newtail = NULL;
//
//    struct ListNode* ret = head;
//
//    while (ret)
//    {
//        // 链表尾空和链表不为空
//        if (ret->val != val)
//        {
//            if(newtail == NULL)
//            {
//                newhead = ret;
//                newtail = ret;
//            }
//            else
//            {
//             newtail->next = ret;
//             newtail = newtail->next;
//             }
//         }
//        ret = ret->next;
//    }
//
//    if (newtail)                                            // 防止出现链表为空的情况，当尾部走到最后一个位置之后对它进行一个最终赋值
//        newtail->next = NULL;
//
//    return newhead;
//
//
//}
//
//
//int main()
//{
//
//    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//
//    node1->val = 1;
//    node2->val = 2;
//    node3->val = 6;
//    node4->val = 3;
//    node5->val = 4;
//    node6->val = 5;
//    node7->val = 6;
//
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//    node7->next = NULL;
//
//
//    struct ListNode* head = node1;
//
//    struct ListNode* newhead = removeElements(head, 6);
//
//    while (newhead)
//    {
//        printf("%d ->", newhead->val);
//        newhead = newhead->next;
//    }
//    printf("NULL");
//
//    return 0;
//}







//	206. 反转链表
//	https://leetcode.cn/problems/reverse-linked-list/description/



 //struct ListNode {
 //    int val;
 //     struct ListNode *next;
 //};

//struct ListNode* reverseList(struct ListNode* head) {
//
//    if (head == NULL)
//        return NULL;
//
//    struct ListNode* tag1, * tag2, * tag3;                         // 三指针移动向后探tag3为tag2指路，tag1为tag2下一跳的指向
//
//    tag1 = NULL;
//    tag2 = head;
//    tag3 = head->next;
//
//    while (tag2)
//    {
//        tag2->next = tag1;
//        tag1 = tag2;
//        tag2 = tag3;
//
//        if (tag3)
//            tag3 = tag3->next;
//    }
//    return tag1;
//
//}



//struct ListNode* reverseList(struct ListNode* head) {
//
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = head;
//
//    while (head)
//    {
//        if (newhead == NULL)
//        {
//            newhead = tail;
//            head = head->next;
//            newhead->next = NULL;
//        }
//        else
//        {
//            head = head->next;
//            tail->next = newhead;
//            newhead = tail;     
//        }
//
//        
//        tail = head;
// 
//    }
//
//    return newhead;
//
//
//}



//int main()
//{
//
//     struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//     node1->val = 1;
//     node2->val = 2;
//     node3->val = 3;
//     node4->val = 4;
//     node5->val = 5;
//     node6->val = 6;
//
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = NULL;
//
//    struct ListNode* head = node1;
//    struct ListNode* tag1 = head;
//    while (tag1)
//    {
//        printf("%d-> ", tag1->val);
//         tag1 = tag1->next;
//    }
//    printf("NULL\n");
//
//    struct ListNode* newhead = reverseList(head);
//
//    while (newhead)
//    {
//        printf("%d-> ", newhead->val);
//        newhead = newhead->next;
//    }
//    printf("NULL\n");
//
//    return 0;
//}







//  876.链表的中间结点
//  https://leetcode.cn/problems/middle-of-the-linked-list/description/



//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* newhead = head;
//
//    int flag = 0;
//    while (newhead)
//    {
//        flag++;
//        newhead = newhead->next;
//    }
//
//    flag /= 2;
//
//
//    struct ListNode* n1 = head;
//
//    while (flag--)
//    {
//        n1 = n1->next;
//    }
//
//    return n1;
//
//}







//	21. 合并两个有序链表
//	https://leetcode.cn/problems/merge-two-sorted-lists/description/

//  struct ListNode {
//      int val;
//      struct ListNode *next;
//  };
// 
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    struct ListNode* tail = NULL;
//    struct ListNode* head = NULL;
//
//    if (list1 == NULL) {
//        return list2;
//    }
//    if (list2 == NULL) {
//        return list1;
//    }
//
//    while (list1 && list2) {
//
//        if (list1->val < list2->val) { 
//            if (head == NULL) {                                     //  代码存在冗余，可以先开辟一块空间作为头部（哨兵位），头部无任何有效数据，最后在定义一个返回指针指向这个头部的下一跳
//                head = tail = list1;
//            }
//            else {
//                tail->next = list1;
//                tail = tail->next;
//            }
//            list1 = list1->next;
//
//        }
//        else {
//            if (head == NULL) {
//                head = tail = list2;
//            }
//            else {
//                tail->next = list2;
//                tail = tail->next;
//            }
//            list2 = list2->next;
//        }
//    }
//
//    if (list1)
//        tail->next = list1;
//    if (list2)
//        tail->next = list2;
//
//
//    return head;
//}


//int main()
//{
//    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//    node1->val = 1;
//    node2->val = 2;
//    node3->val = 4;
//    node4->val = 1;
//    node5->val = 3;
//    node6->val = 4;
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = NULL;
//
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = NULL;
//
//    struct ListNode* list1 = node1;
//    struct ListNode* list2 = node4;
//
//    struct ListNode* ret = mergeTwoLists(list1, list2);
//
//    while (ret)
//    {
//        printf("%d-> ", ret->val);
//        ret = ret->next;
//    }
//    printf("NULL\n");
//
//
//    return 0;
//}








//	面试题 02.04.分割链表
//  https://leetcode.cn/problems/partition-list-lcci/description/

// struct ListNode {
//      int val;
//      struct ListNode *next;
//  };
// 
//struct ListNode* partition(struct ListNode* head, int x) {
//
//    if (head == NULL)
//        return head;
//
//    struct ListNode* pos1 = (struct ListNode*)malloc(sizeof(struct ListNode));      // 哨兵位
//    struct ListNode* pos2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//    struct ListNode* big = pos1;
//    struct ListNode* small = pos2;
//
//    struct ListNode* tmp = head;
//
//    while (tmp)
//    {
//        if (tmp->val >= x)
//        {
//            big->next = tmp;
//            big = big->next;
//        }
//        else
//        {
//            small->next = tmp;
//            small = small->next;
//        }
//        tmp = tmp->next;
//    }
//
//    small->next = pos1->next;
//    big->next = NULL;
//
//    struct ListNode* ret = pos2->next;
//    free(pos1);
//    pos1 = NULL;
//    free(pos2);
//    pos2 = NULL;
//
//    return ret;
//}
//
//
//
//int main()
//{
//    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//    node1->val = 1;
//
//    node1->next = NULL;
//
//    struct ListNode* head = node1;
//
//    partition(head, 2);
//
//    return 0;
//}









#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//  LCR 027. 回文链表
//  https://leetcode.cn/problems/aMhZSa/description/

//bool isPalindrome(struct ListNode* head) {
//
//    struct ListNode* tag1, * tag2, * tag3;
//    tag1 = NULL;
//    tag2 = head;
//    tag3 = head->next;
//    int i = 0;
//    int arr[100000] = { 0 };
//
//    while (tag2)
//    {
//        arr[i++] = tag2->val;
//        tag2->next = tag1;
//        tag1 = tag2;
//        tag2 = tag3;
//        if (tag3)
//            tag3 = tag3->next;
//    }
//
//
//    i = 0;
//    while (tag1 != NULL && head != NULL)
//    {
//        if (arr[i] == tag1->val)
//        {
//            i++;
//            tag1 = tag1->next;
//        }
//        else
//            return false;
//    }
//
//    return true;
//
//}


bool isPalindrome(struct ListNode* head) {

    struct ListNode* slow, * fast;
    slow = fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* tag1, * tag2, * tag3;
    tag1 = NULL;
    tag2 = slow;
    tag3 = slow->next;

    while (tag2)
    {
        tag2->next = tag1;
        tag1 = tag2;
        tag2 = tag3;
        if (tag3)
            tag3 = tag3->next;

        slow = tag1;
    }

    while (slow && head)
    {
        if (slow->val == head->val)
        {
            slow = slow->next;
            head = head->next;
        }
        else
            return false;
    }

    return true;


}


int main()
{

    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->val = 1;
    node2->val = 1;
    node3->val = 2;
    node4->val = 1;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    struct ListNode* head = node1;

    isPalindrome(head);

    
    return 0;
}