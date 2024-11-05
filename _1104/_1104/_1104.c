#define _CRT_SECURE_NO_WARNINGS



//	965. 单值二叉树
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







//	100. 相同的树
//	https://leetcode.cn/problems/same-tree/description/

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)              // 存在一边为空的情况，两边为空在上面
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}







//	572. 另一棵树的子树
//	https://leetcode.cn/problems/subtree-of-another-tree/description/

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {				// 判断两颗树是否相同
//
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)              // 存在一边为空的情况，两边为空在上面
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
//    if (root == NULL)                    // 在向下递归的过程中root为空时
//        return false;
//
//    if (isSameTree(root, subRoot))        // root和subRoot不是相同的树，subRoot不是root的子树
//        return true;
//
//    //继续递归
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//
//}







//	144. 二叉树的前序遍历
//	https://leetcode.cn/problems/binary-tree-preorder-traversal/description/

//int TreeSize(struct TreeNode* root)											// 求二叉树结点个数
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
//    // 第一步：求二叉树的结点个数，以便创建足够的空间
//    *returnSize = TreeSize(root);												// 要求返回一个数组长度即二叉树结点个数
//
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int pi = 0;                         // 下标
//    preorder(root, arr, &pi);													// 传地址使用独立的空间
//
//    return arr;
//}







//	94. 二叉树的中序遍历
//	https://leetcode.cn/problems/binary-tree-inorder-traversal/description/

//int TreeSize(struct TreeNode* root)											// 同上
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







//	145. 二叉树的后序遍历
//	https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

//int TreeSize(struct TreeNode* root)											// 同上
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







//	101. 对称二叉树
//	https://leetcode.cn/problems/symmetric-tree/description/

//bool _isSymmetric(struct TreeNode* root1, struct TreeNode* root2)
//{
//    if (root1 == NULL && root2 == NULL)
//        return true;
//    if (root2 && root1 == NULL || root2 == NULL && root1)						// 两颗树对称部分进行比较
//        return false;
//
//    if (root1->val != root2->val)
//        return false;
//
//    return _isSymmetric(root1->left, root2->right)							// 分成对称部分进行递归
//        && _isSymmetric((root1->right), root2->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    return _isSymmetric(root->left, root->right);								// 分成左右两颗树进行比较
//}







//	二叉树遍历
//	https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef
// 
//	编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
//	例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

//#include <stdio.h>
//#include <sys/types.h>
//#include <stdlib.h>
//
//typedef struct BinaryTreeNode {														// 创建一个结构体类型二叉树
//
//    char Data;
//    struct BinaryTreeNode* left;
//    struct BinaryTreeNode* right;
//
//} BTNode;
//
//BTNode* buyNode(char x)																// 结点申请空间
//{
//    BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
//    ret->Data = x;
//    ret->left = ret->right = NULL;
//
//    return ret;
//}
//
//BTNode* Createtree(char* arr, int* pi)												// 构建二叉树
//{
//    if (arr[*pi] == '#')																// 结点为空时
//    {
//        (*pi)++;
//        return NULL;
//    }
//
//    BTNode* root = buyNode(arr[*pi]);													// 结点不为空申请空间
//    (*pi)++;
//
//    root->left = Createtree(arr, pi);
//    root->right = Createtree(arr, pi);
//
//    return root;
//}
//
//void Inorder(BTNode* root)															// 中序遍历
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
//    BTNode* root = Createtree(arr, &pi);												// 构建的二叉树
//    Inorder(root);
//
//    return 0;
//}