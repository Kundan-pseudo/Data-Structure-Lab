    #include<stdio.h>  
    #include<stdlib.h>      
    struct node  
    {  
        int data;  
        struct node *left;   
        struct node *right;   
    };  
   struct node*insert(struct node*node,int item)
	{
	 if(node==NULL)
	  {
		node=(struct node*)malloc(sizeof(struct node));
		node->data=item;
		node->left=NULL;
		node->right=NULL;
		return node;
	  }
	 else if(item<node->data)
	  {
		node->left=insert(node->left,item);
		return node;
	  }
	 else if(item>node->data)
	  {
		node->right=insert(node->right,item);
		return node;
	  }
	 else
	  {
		printf("Do not enter the same value :");
		exit(0);
	  }
 	}
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // node with minimum value will have no left child
        return find_minimum(root->left); // left most element will be minimum
    return root;
}
struct node* delete(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete(root->right, x);
    else if(x<root->data)
        root->left = delete(root->left, x);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

    void main ()  
    {   struct node *root=NULL;
        int item1,item,choice1;  
         
        printf("which operation you want to do");
        printf("\n1.insert\n2.delete");
                
        while(choice1!=3)
        {
		printf("\nEnter your choice");
	        scanf("%d",&choice1);

        	switch(choice1)
        	{
        		case 1:
			printf("\nEnter the item which you want to insert?\n");  
          		scanf("%d",&item);  
        		root=insert(root,item);
        		break;
        		case 2:
        		printf("\nEnter the item which you want to delete?\n");  
          		scanf("%d",&item1);  
        		root=delete(root,item);
        		break;
        		case 3:
        		exit(0);
        		break;
        		default:
        		printf("invalid choice");
        	}
        }
        		    	
    }  
