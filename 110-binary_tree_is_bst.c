#include "binary_trees.h"
#include <limits.h>  // Include the necessary header for INT_MIN and INT_MAX

/**
 * btib_helper - Function prototype declaration
 */
int btib_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree (BST).
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    // Call the helper function with initial bounds of INT_MIN and INT_MAX
    return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - checks if a binary tree is a valid Binary Search Tree (BST).
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nodes
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (btib_helper(tree->left, min, tree->n - 1) &&
            btib_helper(tree->right, tree->n + 1, max));
}

