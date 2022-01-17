/* In Order -> Left Root Right
 * Pre Order -> Root Left Right
 * Post Order -> Left Right Root
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> left = node -> right = NULL;
    return node;
}

Node* insertLevelOrder(int *arr, Node* root, int i, int n)
{
    if(i < n)
    {
        Node *temp = newNode(arr[i]);
        root = temp;

        root -> left = insertLevelOrder(arr, root->left, 2*i + 1, n);
        root -> right = insertLevelOrder(arr, root->right, 2*i +2, n);
    }

    return root;
}
void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void postOrder(struct Node *root)
{
    if(root != NULL)
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root -> data);
    }
}

int main(void)
{

    int size;
    printf("Enter the array size:");
    scanf("%d", &size);
    int *arr = (int*)calloc(size, sizeof(int));
    printf("Enter %d elements:", size);

    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    Node* root = NULL;
    Node* Root = insertLevelOrder(arr, root, 0, size);
    printf("InOrder Traversal: ");
    inOrder(Root);
    printf("\nPreOrder Traversal: ");
    preOrder(Root);
    printf("\nPostOrder Traversal: ");
    postOrder(Root);

    free(arr);
    free(root);
    free(Root);

}
