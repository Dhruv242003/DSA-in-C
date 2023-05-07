#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};



struct Node* insertNode(struct Node* root, int data) {
   struct Node *new = (struct Node *)(malloc(sizeof(struct Node)));
    if (root == NULL)
    {
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        root = new;
        return root;
    }
    else
    {
        struct Node *temp = root;     // For traversing
        while (1)
        {
            if (temp->data > data)
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    new->data = data;
                    new->left = NULL;
                    new->right = NULL;
                    temp->left = new;
                    return root;
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    new->data = data;
                    new->left = NULL;
                    new->right = NULL;
                    temp->right = new;
                    return root;
                }
            }
        }
    }
}

void postorderTraversal(struct Node* root) {   // LRD
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    struct Node* stack[100];
    int top = -1;
    struct Node* prev = NULL;
    struct Node *temp = root;
    do {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left;
        }
        while (temp == NULL && top != -1) {
            temp = stack[top];
            if (temp->right == NULL || temp->right == prev) {
                printf("%d ", temp->data);
                prev = temp;
                top--;
                temp = NULL;
            } else {
                temp = temp->right;
            }
        }
    } while (top != -1);
}



void preorderTraversal(struct Node* root) {     // DLR
    if (root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* currentNode = stack[top--];
        printf("%d ", currentNode->data);
        if (currentNode->right != NULL){
            stack[++top] = currentNode->right;
        } 
        if (currentNode->left != NULL){
            stack[++top] = currentNode->left;
        }
    }
}

void inorderTraversal(struct Node* root) {
    if (root == NULL){
        return;
    }
    struct Node* stack[100];
    int top = -1;
    struct Node* currentNode = root;
    while (currentNode != NULL || top >= 0) {
        while (currentNode != NULL) {
            stack[++top] = currentNode;
            currentNode = currentNode->left;
        }
        currentNode = stack[top--];
        printf("%d ", currentNode->data);
        currentNode = currentNode->right;
    }
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* current = stack[top--];
        if (current->left == NULL && current->right == NULL) {
            count++;
        } else {
            if (current->right != NULL) {
                stack[++top] = current->right;
            }
            if (current->left != NULL) {
                stack[++top] = current->left;
            }
        }
    }
    return count;
}

void mirrorImage(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;


    while (top >= 0) {
        struct Node* current = stack[top--];
        
        struct Node* temp = current->left;

        
        current->left = current->right;
        current->right = temp;


        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}



// void deleteNode(struct Node* root, int value) {
//     struct Node* parent = NULL;
//     struct Node* currentNode = root;



//     while (currentNode != NULL && currentNode->data != value) {
//         parent = currentNode;
//         if (value < currentNode->data) {
//             currentNode = currentNode->left;
//         } else {
//             currentNode = currentNode->right;
//         }
//     }




//     if (currentNode == NULL) {
//         printf("Node not found in the tree.\n");
//         return;
//     }


//     if (currentNode->left == NULL && currentNode->right == NULL) {
//         if (currentNode == root) {
//             root = NULL;
//         } 
//         else if (currentNode == parent->left) {
//             parent->left = NULL;
//         } else {
//             parent->right = NULL;
//         }
//         free(currentNode);

//     } 


//     else if (currentNode->left == NULL) {
//         if (currentNode == root) {
//             root = currentNode->right;
//         } 
        
//         else if (currentNode == parent->left) {
//             parent->left = currentNode->right;
//         } else {
//             parent->right = currentNode->right;
//         }
//         free(currentNode);
//     } 
    
    
    
//     else if (currentNode->right == NULL) {
//         if (currentNode == root) {
//             root = currentNode->left;
//         } else if (currentNode == parent->left) {
//             parent->left = currentNode->left;
//         } else {
//             parent->right = currentNode->left;
//         }
//         free(currentNode);
//     } 
    
//     else {
//         struct Node* replacementNode = currentNode->right;
//         while (replacementNode->left != NULL) {
//             replacementNode = replacementNode->left;
//         }
//         currentNode->data = replacementNode->data;
//         deleteNode(currentNode->right, replacementNode->data);
//     }
// }


struct Node *inOrderPredecessor(struct Node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}


struct Node *deleteNode(struct Node *root, int value){

    struct Node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }

    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }


    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}




int main() {
    struct Node* root = NULL;
    
    int n;
    printf("Enter the number of nodes in the BST:");
    scanf("%d", &n);
    printf("Enter the data of nodes:");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        root = insertNode(root, data);
    }


    // printf("Preorder Traversal: \n");
    // preorderTraversal(root);
    // printf("\n");
    // printf("Inorder Traversal\n");
    // inorderTraversal(root);
    // printf("\n");
    // printf("postOrder Traversal\n");
    // postorderTraversal(root);
    // printf("\n");
    // printf("Number of Leaf Nodes:  %d\n",countLeafNodes(root));
    // printf("\n");
    // printf("Mirror Image Done\n");
    // mirrorImage(root);
    // printf("\n");
    // printf("Preorder Traversal: \n");
    // preorderTraversal(root);
    // printf("\n");
    // printf("Inorder Traversal\n");
    // inorderTraversal(root);
    // printf("\n");
    // printf("postOrder Traversal\n");
    // postorderTraversal(root);
    // printf("\n");
    // printf("Number of Leaf Nodes:  %d\n",countLeafNodes(root));
    // printf("\n");


    printf("Enter value to delete\n");
    int a;
    scanf("%d",&a);
    printf("Inorder Traversal\n");
    inorderTraversal(root);
    printf("\n");
    printf("Number of Leaf Nodes:  %d\n",countLeafNodes(root));
    printf("\n");

    printf("after deleting\n");
    deleteNode(root,a);
    printf("Inorder Traversal\n");
    inorderTraversal(root);
    printf("\n");
    printf("Number of Leaf Nodes:  %d\n",countLeafNodes(root));
    printf("\n");


}
