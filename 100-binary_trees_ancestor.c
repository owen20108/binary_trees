#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: a pointer to the lowest common ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t depth_first, depth_second;

    // Check if either of the input nodes is NULL
    if (!first || !second)
        return (NULL);

    // Calculate the depth of each node
    depth_first = binary_tree_depth(first);
    depth_second = binary_tree_depth(second);

    // Adjust the pointers to the same depth
    while (depth_first > depth_second)
    {
        first = first->parent;
        depth_first--;
    }
    while (depth_second > depth_first)
    {
        second = second->parent;
        depth_second--;
    }

    // Move both pointers up until the common ancestor is found
    while (first && second)
    {
        if (first == second)
            return ((binary_tree_t *)first);

        first = first->parent;
        second = second->parent;
    }

    // If no common ancestor is found, return NULL
    return ((binary_tree_t *)NULL);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    // Check if the input node is NULL
    if (!tree)
        return (0);

    // Calculate the depth by moving up the tree until the root
    while (tree->parent)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}

