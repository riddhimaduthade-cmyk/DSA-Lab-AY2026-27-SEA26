// Name: Riddhima Duthade
// Roll no: SEA26
// Binary Search Tree Operations for Online Directory Systems

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BST{
    char name[10], phone[11];
    struct BST *left, *right;
}BST;
void main(){
    BST *root = NULL, *nw, *temp;
    int op, ans;
    char key[10];
    void insert(BST *, BST *);
    void inorder(BST *);
    void preorder(BST *);
    void postorder(BST *);
    void search(BST *, char *);
    do{
        printf("\n1. Create\n2. Traverse\n3. Search\n4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &op);
        switch(op){
        case 1:
            do{
                nw = (BST*)malloc(sizeof(BST));
                printf("Enter Contact's name: ");
                scanf("%s", nw->name);
                printf("Enter Contact's phone: ");
                scanf("%s", nw->phone);
                nw->left = NULL;
                nw->right = NULL;
                if(root == NULL){
                    root = nw;
                }else{
                    insert(root, nw);
                }
                printf("Do you want to continue? : ");
                scanf("%d", &ans);
            }while(ans == 1);
            break;
        case 2:
            if(root == NULL){
                printf("Tree is not created\n");
            }else{
                printf("Travrsals for given tree are: \n");
                printf("Inorder: ");
                inorder(root);
                printf("\nPreorder: ");
                preorder(root);
                printf("\nPostorder: ");
                postorder(root);
            }
            break;

        case 3:
            if(root == NULL){
                printf("Tree is not created\n");
            }else{
                printf("Enter contact name to search: ");
                scanf("%s", key);
                search(root, key);
            }
            break;
        case 4:
            printf("Exited Successfully\n");
            break;
        default:
            printf("Invalid Option\n"); 
        }
    }while(op != 4);
}
void insert(BST *root, BST *nw){
    if(strcasecmp(nw->name, root->name) < 0){
        if(root->left == NULL){
            root->left = nw;
        }else{
            insert(root->left, nw);
        }
    }
    if(strcasecmp(nw->name, root->name) > 0){
        if(root->right == NULL){
            root->right = nw;
        }else{
            insert(root->right, nw);
        }
    }
}
void inorder(BST *temp){
    if(temp != NULL){
        inorder(temp->left);
        printf("%s ", temp->name);
        inorder(temp->right);
    }
}
void preorder(BST *temp){
    if(temp != NULL){
        printf("%s ", temp->name);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(BST *temp){
    if(temp != NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%s ", temp->name);
    }
    printf("\n");
}

void search(BST *root, char *key){
    if(root == NULL){
        printf("\nContact not found");
        return;
    }
    if(strcasecmp(key, root->name) == 0){
        printf("Contact found");
        printf("\nName: %s", root->name);
        printf("\nPhone: %s\n", root->phone);
    }
    else if(strcasecmp(key, root->name) < 0){
        search(root->left, key);
    }
    else{
        search(root->right, key);
    }
}
