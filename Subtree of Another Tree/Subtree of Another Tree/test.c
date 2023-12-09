#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    if (root != NULL && subRoot == NULL)
    {
        return false;
    }
    if (root == NULL && subRoot != NULL)
    {
        return false;
    }
    if (root->val == subRoot->val)
    {
        return isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right);
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->left, subRoot);
}