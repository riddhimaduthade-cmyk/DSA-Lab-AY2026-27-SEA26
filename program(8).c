// Name: Riddhima Duthade
// Roll no: SEA26
// BINARY SEARCH TREE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bst
{
    char name[50],phone[15];
    struct bst *left,*right;
}node;
void insert(node *root,node *nw)
{
    if(strcmp(nw->name,root->name)<0)
    {
        if(root->left==NULL) root->left=nw;
        else insert(root->left,nw);
    }
    else
    {
        if(root->right==NULL) root->right=nw;
        else insert(root->right,nw);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%s\t%s\n",root->name,root->phone);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%s\t%s\n",root->name,root->phone);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%s\t%s\n",root->name,root->phone);
    }
}
void search(node *root,char key[])
{
    if(root==NULL)
        printf("\nName not found.");
    else if(strcmp(key,root->name)==0)
        printf("\nName: %s\nPhone: %s",root->name,root->phone);
    else if(strcmp(key,root->name)<0)
        search(root->left,key);
    else
        search(root->right,key);
}
int main()
{
    int op,ans;
    char key[50];
    node *nw,*root=NULL;

    do
    {
        printf("\n1.CREATE\n2.SEARCH\n3.TRAVERSALS\n4.EXIT");
        printf("\nEnter your option: ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                do
                {
                    nw=(node*)malloc(sizeof(node));
                    nw->left=NULL;
                    nw->right=NULL;

                    printf("\nEnter name: ");
                    scanf("%s",nw->name);
                    printf("Enter phone: ");
                    scanf("%s",nw->phone);

                    if(root==NULL) root=nw;
                    else insert(root,nw);

                    printf("Continue? (1/0): ");
                    scanf("%d",&ans);
                }while(ans==1);
                break;

            case 2:
                printf("\nEnter name to search: ");
                scanf("%s",key);
                search(root,key);
                break;

            case 3:
                printf("\nINORDER:\n");
                inorder(root);
                printf("\nPREORDER:\n");
                preorder(root);
                printf("\nPOSTORDER:\n");
                postorder(root);
                break;

            case 4:
                break;

            default:
                printf("\nInvalid option.");
        }
    }while(op!=4);

    return 0;
}


