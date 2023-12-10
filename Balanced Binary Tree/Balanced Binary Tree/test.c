#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    int gap = TreeDepth(root->left) - TreeDepth(root->right);
    if (abs(gap) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}