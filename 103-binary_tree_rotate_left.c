#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: The root node of the tree
 *
 * Return: Pointer to the new root node after rotation
 *         NULL if tree is NULL or has no right child
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *pivot;

    // Check if tree or its right child is NULL
    if (tree == NULL || tree->right == NULL)
    {
        return (NULL);
    }

    // Perform left rotation
    pivot = tree->right;
    tree->right = pivot->left;

    // Update parent pointers
    if (pivot->left != NULL)
    {
        pivot->left->parent = tree;
    }

    // Update links to perform the rotation
    pivot->left = tree;
    pivot->parent = tree->parent;
    tree->parent = pivot;

    // Return the new root node after rotation
    return (pivot);
}

