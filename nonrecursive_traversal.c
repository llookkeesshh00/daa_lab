#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *stack[10];
int top=-1;
void push(struct node *t)
{
    stack[++top]=t;
}

struct node * pop()
{
    return stack[top--];
}

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}


void preorder( struct node *root)
{ struct node * temp=root;
   push(root);
   
    while(top!=-1)
    { temp=pop();
      printf("%d ",temp->data);
       if(temp->right!=NULL)
       { push(temp->right);
        

       }
    
      if(temp->left!=NULL)
      { 
        push(temp->left);
         
       

      }

    }
  



}




void inorder(struct node * root)
{ struct node *temp=root;
   while(1)
   {  if(temp!=NULL)
      {    push(temp);
          temp=temp->left;

     }
     else
     { if(top==-1) break;
       
       temp=pop();
       printf("%d ",temp->data);
       temp=temp->right;


     }



   }

}

int main()
{
    struct node *n;
    struct node *n1;
    struct node *n2;
    struct node *n3;
    struct node *n4;
    // creating and intializing data
    n = createnode(6);
    n1 = createnode(4);
    n2 = createnode(8);
    n3 = createnode(2);
    n4 = createnode(5);
    // linking elements
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    printf("\ninorder traverasal is\n");
    preorder(n);
    inorder(n);
}