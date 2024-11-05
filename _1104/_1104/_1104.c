#define _CRT_SECURE_NO_WARNINGS



//	965. ��ֵ������
//	https://leetcode.cn/problems/univalued-binary-tree/description/

//bool isUnivalTree(struct TreeNode* root) {
//
//    if (root == NULL)
//        return true;
//
//    if (root->left && root->val != root->left->val)
//        return false;
//
//    if (root->right && root->val != root->right->val)
//        return false;
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//
//}







//	100. ��ͬ����
//	https://leetcode.cn/problems/same-tree/description/

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)              // ����һ��Ϊ�յ����������Ϊ��������
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}







//	572. ��һ����������
//	https://leetcode.cn/problems/subtree-of-another-tree/description/

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {				// �ж��������Ƿ���ͬ
//
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)              // ����һ��Ϊ�յ����������Ϊ��������
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//
//    if (root == NULL)                    // �����µݹ�Ĺ�����rootΪ��ʱ
//        return false;
//
//    if (isSameTree(root, subRoot))        // root��subRoot������ͬ������subRoot����root������
//        return true;
//
//    //�����ݹ�
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//
//}







//	144. ��������ǰ�����
//	https://leetcode.cn/problems/binary-tree-preorder-traversal/description/

//int TreeSize(struct TreeNode* root)											// �������������
//{
//    if (root == NULL)
//        return 0;
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
//void preorder(struct TreeNode* root, int* arr, int* pi)						
//{
//    if (root == NULL)
//        return;
//
//    arr[(*pi)++] = root->val;
//    preorder(root->left, arr, pi);
//    preorder(root->right, arr, pi);
//
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    // ��һ������������Ľ��������Ա㴴���㹻�Ŀռ�
//    *returnSize = TreeSize(root);												// Ҫ�󷵻�һ�����鳤�ȼ�������������
//
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int pi = 0;                         // �±�
//    preorder(root, arr, &pi);													// ����ַʹ�ö����Ŀռ�
//
//    return arr;
//}







//	94. ���������������
//	https://leetcode.cn/problems/binary-tree-inorder-traversal/description/

//int TreeSize(struct TreeNode* root)											// ͬ��
//{
//    if (root == NULL)
//        return 0;
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
//void preorder(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)
//        return;
//
//    preorder(root->left, arr, pi);
//    arr[(*pi)++] = root->val;
//    preorder(root->right, arr, pi);
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int pi;
//    preorder(root, arr, &pi);
//
//    return arr;
//
//}







//	145. �������ĺ������
//	https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

//int TreeSize(struct TreeNode* root)											// ͬ��
//{
//    if (root == NULL)
//        return 0;
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
//void preorder(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)
//        return;
//
//    preorder(root->left, arr, pi);
//    preorder(root->right, arr, pi);
//    arr[(*pi)++] = root->val;
//}
//
//
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//
//    int pi = 0;
//    preorder(root, arr, &pi);
//
//    return arr;
//}







//	101. �Գƶ�����
//	https://leetcode.cn/problems/symmetric-tree/description/

//bool _isSymmetric(struct TreeNode* root1, struct TreeNode* root2)
//{
//    if (root1 == NULL && root2 == NULL)
//        return true;
//    if (root2 && root1 == NULL || root2 == NULL && root1)						// �������ԳƲ��ֽ��бȽ�
//        return false;
//
//    if (root1->val != root2->val)
//        return false;
//
//    return _isSymmetric(root1->left, root2->right)							// �ֳɶԳƲ��ֽ��еݹ�
//        && _isSymmetric((root1->right), root2->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    return _isSymmetric(root->left, root->right);								// �ֳ��������������бȽ�
//}







//	����������
//	https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef
// 
//	��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//	�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������

//#include <stdio.h>
//#include <sys/types.h>
//#include <stdlib.h>
//
//typedef struct BinaryTreeNode {														// ����һ���ṹ�����Ͷ�����
//
//    char Data;
//    struct BinaryTreeNode* left;
//    struct BinaryTreeNode* right;
//
//} BTNode;
//
//BTNode* buyNode(char x)																// �������ռ�
//{
//    BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
//    ret->Data = x;
//    ret->left = ret->right = NULL;
//
//    return ret;
//}
//
//BTNode* Createtree(char* arr, int* pi)												// ����������
//{
//    if (arr[*pi] == '#')																// ���Ϊ��ʱ
//    {
//        (*pi)++;
//        return NULL;
//    }
//
//    BTNode* root = buyNode(arr[*pi]);													// ��㲻Ϊ������ռ�
//    (*pi)++;
//
//    root->left = Createtree(arr, pi);
//    root->right = Createtree(arr, pi);
//
//    return root;
//}
//
//void Inorder(BTNode* root)															// �������
//{
//    if (root == NULL)
//        return;
//
//    Inorder(root->left);
//    printf("%c ", root->Data);
//    Inorder(root->right);
//}
//
//int main() {
//
//    char arr[52] = { 0 };
//    scanf("%s", arr);
//
//    int pi = 0;
//    BTNode* root = Createtree(arr, &pi);												// �����Ķ�����
//    Inorder(root);
//
//    return 0;
//}