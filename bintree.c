#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}//

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
        
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {   printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
        
    }
}

// this function is to create bst
struct node * insert(struct node * root,int data)
{ if(root==NULL)
  {  return createnode(data);

  }
  if(root->data<data)
  { root->right=insert(root->right,data);


  }
  else
   { root->left=insert(root->left,data);


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
    inOrder(n);
}