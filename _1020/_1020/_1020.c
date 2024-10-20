#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>



//  160. 相交链表
//  https://leetcode.cn/problems/intersection-of-two-linked-lists/description/

//struct ListNode {
//     int val;
//      struct ListNode *next;
// };
// 
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//
//    struct ListNode* A = headA;
//    struct ListNode* B = headB;
//    int a = 0;
//    int b = 0;
//
//
//    while (A->next)
//    {
//        A = A->next;
//        a++;
//    }
//    while (B->next)
//    {
//        B = B->next;
//        b++;
//    }
//
//
//    if (A != B)
//        return NULL;
//
//    int i = abs(a - b);
//
//    struct ListNode* longlink, * shortlink;
//    longlink = shortlink = NULL;
//
//    if (a > b)
//    {
//        longlink = headA;
//        shortlink = headB;
//    }
//    else
//    {
//        longlink = headB;
//        shortlink = headA;
//    }
//
//
//    while (i--)
//        longlink = longlink->next;
//
//
//    while (longlink && shortlink)
//    {
//        if (longlink != shortlink)
//        {
//            longlink = longlink->next;
//            shortlink = shortlink->next;
//        }
//        else
//            return longlink;
//
//    }
//
//    return NULL;
//
//}







//	面试题 02.02. 返回倒数第 k 个节点
//	https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/description/

//struct ListNode {
//     int val;
//      struct ListNode *next;
// };
//
//int kthToLast(struct ListNode* head, int k) {
//
//    struct ListNode* newhead = head;
//    int i = 0;
//
//    while (newhead)
//    {
//        i++;
//        newhead = newhead->next;
//    }
//
//    i -= k;
//
//    while (i--)
//    {
//        head = head->next;
//    }
//
//    return head->val;
//}

//	双指针

//int kthToLast(struct ListNode* head, int k) {
//    struct ListNode* newhead = head;
//    struct ListNode* newtail = head;
//
//    while (k--)
//        newtail = newtail->next;
//
//    while (newtail)
//    {
//        newhead = newhead->next;
//        newtail = newtail->next;
//    }
//
//    return newhead->val;
//}







//	141. 环形链表
//	https://leetcode.cn/problems/linked-list-cycle/description/

//bool hasCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//            return true;
//    }
//
//    return false;
//}







//	142. 环形链表 II
//	https://leetcode.cn/problems/linked-list-cycle-ii/description/

//struct ListNode* detectCycle(struct ListNode* head) {
//
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//    int pos = 0;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            while (head != slow)
//            {
//                head = head->next;
//                slow = slow->next;
//            }
//            return head;
//
//        }
//
//    }
//
//    return NULL;
//
//}







//	138. 随机链表的复制
//	https://leetcode.cn/problems/copy-list-with-random-pointer/description/

//struct Node* AddNode(int val)
//{
//    struct Node* ret = (struct Node*)malloc(sizeof(struct Node));
//    ret->val = val;
//    ret->next = ret->random = NULL;
//
//    return ret;
//}
//
//struct Node* copyRandomList(struct Node* head) {
//
//    if (head == NULL)
//        return NULL;
//
//
//    struct Node* pcur = head;
//
//    while (pcur)
//    {
//        struct Node* copy = AddNode(pcur->val);
//        copy->next = pcur->next;
//        pcur->next = copy;
//
//        pcur = copy->next;
//    }
//
//    struct Node* newcopy = head->next;
//    struct Node* newhead = head;
//
//    while (newhead)
//    {
//        newcopy = newhead->next;
//        if (newhead->random)
//            newcopy->random = newhead->random->next;
//
//        newhead = newcopy->next;
//    }
//
//    struct Node* newlink = head->next;
//    struct Node* tail = head->next;
//
//    while (tail->next)
//    {
//        head = tail->next;
//        tail->next = head->next;
//        tail = head->next;
//    }
//
//
//    return newlink;
//}