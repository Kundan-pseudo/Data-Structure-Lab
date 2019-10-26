    #include<stdio.h>  
    #include<stdlib.h>      
    struct node  
    {  
        int data;  
        struct node *left;   
        struct node *right;   
    };  
   int small=0,large=0;
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
	{if(root->data<small){small=root->data;}
	 else if(root->data>large){large=root->data;}
	 	preorder(root->left);
	 	preorder(root->right);
	             
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
	small=root->data;
        		printf("preorder:");
        		preorder(root);
			printf("%d %d",large,small);
        		    	
    }  
