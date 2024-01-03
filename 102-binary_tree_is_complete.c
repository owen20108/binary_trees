#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t size;

    // Check if tree is NULL
    if (!tree)
        return (0);

    // Calculate the size of the tree
    size = binary_tree_size(tree);

    // Check if the tree is complete using helper function
    return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - assists in checking if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
    // Check if tree is NULL
    if (!tree)
        return (1);

    // Check if the current index exceeds the size of the tree
    if (index >= size)
        return (0);

    // Recursively check if both left and right subtrees are complete
    return (btic_helper(tree->left, 2 * index + 1, size) &&
            btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    // Check if tree is NULL
    if (!tree)
        return (0);

    // Calculate the size of the tree recursively
    return (binary_tree_size(tree->left) +
            binary_tree_size(tree->right) + 1);
}

