#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// function prototypes
struct node *create_node(int key);
struct node *insert_key(struct node *node, int key);
struct node *delete_key(struct node *root, int key);
void inorder_traversal(struct node *root);
void preorder_traversal(struct node *root);
void postorder_traversal(struct node *root);

int main()
{
    struct node *root = NULL;
    int choice, key;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1. Insert a key\n");
        printf("2. Delete a key\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert_key(root, key);
            printf("%d inserted successfully\n", key);
            break;
        case 2:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = delete_key(root, key);
            printf("%d deleted successfully\n", key);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorder_traversal(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorder_traversal(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal: ");
            postorder_traversal(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

// function to create a new node
struct node *create_node(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to insert a key in the BST
struct node *insert_key(struct node *node, int key)
{
    if (node == NULL)
    {
        return create_node(key);
    }
    if (key < node->key)
    {
        node->left = insert_key(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert_key(node->right, key);
    }
    return node;
}

// function to delete a key from the BST
struct node *delete_key(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = delete_key(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete_key(root->right, key);
    }
    else
    {
        // found the key
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // node
        // node with two children: get the inorder successor (smallest
        // in the right subtree)
        struct node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        // copy the inorder successor's key to this node
        root->key = temp->key;
        // delete the inorder successor
        root->right = delete_key(root->right, temp->key);
    }
    return root;
}

// function for inorder traversal of BST
void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

// function for preorder traversal of BST
void preorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// function for postorder traversal of BST
void postorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->key);
    }
}

// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 1
// Enter the key to insert: 5
// 5 inserted successfully
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 1
// Enter the key to insert: 3
// 3 inserted successfully
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 1
// Enter the key to insert: 7
// 7 inserted successfully
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 3
// Inorder Traversal: 3 5 7 
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 4
// Preorder Traversal: 5 3 7 
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 5
// Postorder Traversal: 3 7 5 
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 2
// Enter the key to delete: 5
// 5 deleted successfully
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 3
// Inorder Traversal: 3 7 
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit
// 4
// Preorder Traversal: 7 3 
// Enter your choice:
// 1. Insert a key
// 2. Delete a key
// 3. Inorder Traversal
// 4. Preorder Traversal
// 5. Postorder Traversal
// 6. Exit