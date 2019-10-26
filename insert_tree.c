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
    void preorder(struct node *root)
    {
	if(root!=NULL)
	{printf("\nThe element %d ",root->data);
	 preorder(root->left);
	 preorder(root->right);
        }
    }
    void inorder(struct node *root)
    {
    	if(root!=NULL)
    	{
    	inorder(root->left);
	printf("\nThe element %d ",root->data);
	inorder(root->right);
    	}
    }
    void postorder(struct node *root)
    {
    	if(root!=NULL)
    	{
	postorder(root->left);
    	postorder(root->right);
	printf("\n THe element %d ",root->data);  
	}
    }	
    void main ()  
    {   struct node *root=NULL;
        int choice,item,choice1;  
        do   
        {  
            printf("\nEnter the item which you want to insert?\n");  
            scanf("%d",&item);  
            root=insert(root,item);  
            printf("\nPress 0 to insert more ?\n");  
            scanf("%d",&choice); 
            
        }while(choice == 0); 
        printf("which operation you want to do");
        printf("\n1.inorder\n2.preorder\n3.postorder\n4.exit\n");
                
        while(choice!=4)
        {
		printf("enter your choice");
	        scanf("%d",&choice1);

        	switch(choice1)
        	{
        		case 1:
        		printf("inorder:"); 
        		inorder(root);
        		break;
        		case 2:
        		printf("preorder:");
        		preorder(root);
        		break;
        		case 3:
        		printf("postorder:");
        		postorder(root);
        		break;
        		case 4:
        		exit(0);
        		break;
        		default:
        		printf("invalid choice");
        	}
        }
        		    	
    }  
