#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;
}treeNode;

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return FindMin(node->left);
        else 
                return node;
}
treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->right) /* Go to the left sub tree to find the min element */
                FindMax(node->right);
        else 
                return node;
}

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        return node;

}
int total(treeNode *root){
	if (root==NULL) return 0;
	if (root->left==NULL&&root->right==NULL){
		printf("%d ", root->data); return 1;
	}
	else return (total(root->left)+total(root->right));
}
int main()
{
      treeNode *root = NULL; int x = 0; 
        printf("Enter data: (-1 to stop) "); scanf("%d",&x);
        while (x!=-1){
        	root = Insert(root, x);scanf("%d",&x);
		}
		printf("\nLeaf nodes count: %d", total(root));
		
}
