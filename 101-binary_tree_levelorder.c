#include "binary_trees.h"

/**
 * binary_tree_levelorder - performs a level-order traversal on a binary tree
 * @tree: pointer to the root of the binary tree
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t level, max_level;

    // Check if tree or func is NULL
    if (!tree || !func)
        return;

    // Calculate the maximum level of the tree
    max_level = binary_tree_height(tree) + 1;

    // Traverse the tree level by level and call the provided function
    for (level = 1; level <= max_level; level++)
        btlo_helper(tree, func, level);
}

/**
 * btlo_helper - assists in level-order traversal of a binary tree
 * @tree: pointer to the current node in the traversal
 * @func: pointer to a function to call for each node
 * @level: the current level of the tree
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
    // Base case: call the function when the current level is reached
    if (level == 1)
        func(tree->n);
    else
    {
        // Recursive calls to traverse the left and right subtrees
        btlo_helper(tree->left, func, level - 1);
        btlo_helper(tree->right, func, level - 1);
    }
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root of the binary tree
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l = 0;
    size_t height_r = 0;

    // Base case: return 0 if the tree is NULL
    if (!tree)
        return (0);

    // Calculate the height of the left and right subtrees
    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    // Return the maximum height between left and right subtrees
    return (height_l > height_r ? height_l : height_r);
}

