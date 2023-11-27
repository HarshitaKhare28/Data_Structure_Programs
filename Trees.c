#include <stdio.h>
#include <stdlib.h>
struct Trees
{
    int data;
    struct Trees *left;
    struct Trees *right;
};
typedef struct Trees tree;
// create function for tree
void create_tree(tree **node)
{
    *node = NULL;
    tree *prev, *ptr;
    int a[] = {22, 12, 34, 29, 30, 18, 25, 10};
    for (int i = 0; i < 8; i++)
    {
        tree *temp = (tree *)malloc(sizeof(tree));
        temp->data = a[i];
        temp->left = NULL;
        temp->right = NULL;
        if (*node == NULL)
        {
            *node = temp;
        }
        else
        {
            ptr = *node;
            prev = NULL;
            while (ptr != NULL)
            {
                prev = ptr;
                if (temp->data > ptr->data)
                {
                    ptr = ptr->right;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            if (temp->data > prev->data)
            {
                prev->right = temp;
            }
            else
            {
                prev->left = temp;
            }
        }
    }
}
// print preorder traversal
void preorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d\t", node->data);
    preorder(node->left);
    preorder(node->right);
}
// print inorder traversal
void inorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d\t", node->data);
    inorder(node->right);
}
// print postorder traversal
void postorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d\t", node->data);
}
// count internal nodes
int find_internal_nodes(tree *node)
{
    if (node == NULL || node->left == NULL && node->right == NULL)
    {
        return 0;
    }
    return 1 + find_internal_nodes(node->left) + find_internal_nodes(node->right);
}
// count terminal/child nodes
int find_child_nodes(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    else
    {
        return find_child_nodes(node->left) + find_child_nodes(node->right);
    }
}
// count half nodes
int find_half_nodes(tree *node)
{
    int count = 0;
    if (node == NULL)
    {
        return 0;
    }
    if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL))
    {
        count = 1;
    }
    return count + find_half_nodes(node->left) + find_half_nodes(node->right);
}
// count full nodes
// full node- a node that has both left and right node as non-empty
int find_full_nodes(tree *node)
{
    int count = 0;
    if (node == NULL)
    {
        return 0;
    }
    if (node->left != NULL && node->right != NULL)
    {
        count = 1;
    }
    return count + find_full_nodes(node->left) + find_full_nodes(node->right);
}
// height of the tree
int height(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL)
    {
        return 0;
    }
    int left_tree = height(node->left);
    int right_tree = height(node->right);
    if (left_tree > right_tree)
    {
        return left_tree + 1;
    }
    else
    {
        return right_tree + 1;
    }
}
int main()
{
    tree *root;
    root = NULL;
    create_tree(&root);
    printf("\n---Pre order---\n");
    preorder(root);
    printf("\n---In order---\n");
    inorder(root);
    printf("\n---Post order---\n");
    postorder(root);
    printf("\nInternal nodes are: %d\n", find_internal_nodes(root));
    printf("\nChild nodes are: %d\n", find_child_nodes(root));
    printf("\nHalf nodes are: %d\n", find_half_nodes(root));
    printf("\nFull nodes are: %d\n", find_full_nodes(root));
    printf("\nHeight of tree is: %d\n", height(root));
    return 0;
}
