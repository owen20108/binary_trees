#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Description:
 * This function creates a new binary tree node with the specified value
 * and parent node. It allocates memory for the new node and initializes
 * its properties. If the allocation fails, it returns NULL.
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    /* Declare a new binary tree node pointer */
    binary_tree_t *newNode;

    /* Allocate memory for the new node */
    newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

    /* Check if memory allocation was successful */
    if (newNode == NULL)
    {
        /* Return NULL on failure */
        return (NULL);
    }

    /* Assign values to the properties of the new node */
    newNode->parent = parent;
    newNode->n = value;
    newNode->left = NULL;
    newNode->right = NULL;

    /* Return a pointer to the new node */
    return (newNode);
}

