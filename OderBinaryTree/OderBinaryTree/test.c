#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct treenode
{
    char val;
    struct treenode* left;
    struct treenode* right;
}treenode;

treenode* createtree(char* str, int* i)
{
    if (str[*i] == '#')
    {
        (*i)++;
        return NULL;
    }
    else
    {
        treenode* root = (treenode*)malloc(sizeof(treenode));
        root->val = str[*i];
        (*i)++;
        root->left = createtree(str, i);
        root->right = createtree(str, i);
        return root;
    }
}
void InOrder(treenode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);

}
int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    treenode* root = createtree(str, &i);
    InOrder(root);
    return 0;
}