#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a binary search tree
 * @root: Pointer to the root node of the BST
 * @value: Value to be inserted
 *
 * Return: Pointer to the root node after insertion
 */
bst_t *bst_insert(bst_t **root, int value)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(bst_t));
        if (*root == NULL)
            return (NULL);
        (*root)->n = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return (*root);
    }

    if (value < (*root)->n)
        return (bst_insert(&((*root)->left), value));
    if (value > (*root)->n)
        return (bst_insert(&((*root)->right), value));

    return (NULL); // Value already exists
}

/**
 * bst_remove - Removes a node with the specified value from a binary search tree
 * @root: Pointer to the root node of the BST
 * @value: Value to be removed
 *
 * Return: Pointer to the root node after removal
 */
bst_t *bst_remove(bst_t **root, int value)
{
    if (*root == NULL)
        return (NULL);

    if (value < (*root)->n)
        (*root)->left = bst_remove(&((*root)->left), value);
    else if (value > (*root)->n)
        (*root)->right = bst_remove(&((*root)->right), value);
    else
    {
        if ((*root)->left == NULL)
        {
            bst_t *temp = (*root)->right;
            free(*root);
            return (temp);
        }
        else if ((*root)->right == NULL)
        {
            bst_t *temp = (*root)->left;
            free(*root);
            return (temp);
        }

        bst_t *temp = bst_find_min((*root)->right);
        (*root)->n = temp->n;
        (*root)->right = bst_remove(&((*root)->right), temp->n);
    }
    return (*root);
}

/**
 * bst_search - Searches for a node with the specified value in a binary search tree
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for
 *
 * Return: Pointer to the node with the specified value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL || tree->n == value)
        return ((bst_t *)tree);

    if (value < tree->n)
        return (bst_search(tree->left, value));
    else
        return (bst_search(tree->right, value));
}
)
