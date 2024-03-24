#include<stdio.h>
#include<stdlib.h>

#define tablesize 7
struct node 
{ int data;
 struct node *next ;

};
struct node  *hashtable[tablesize];


int hashfunction(int key)
{
    return key%tablesize;
}

void insert(int key)
{  int index=hashfunction(key);
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=key;
    new->next=NULL ;

  if(hashtable[index]==NULL)
   { hashtable[index]=new;

   }//to aviod collison we chain the keys
   else
   { struct node *temp=hashtable[index];
     while(temp->next!=NULL)
     {
        temp=temp->next;
     } 
     temp->next= new;

   }



}


void display()
{ struct node * temp;
   for(int i=0;i<tablesize;i++)
   { temp=hashtable[i];
    printf("chain[%d]-->",i);
     while(temp)
     {
        printf("%d-->",temp->data);
        temp=temp->next;
     }
  printf("\n");



   }



}
int search(int value)
{
    int key = value % tablesize;
    struct node *temp = hashtable[key];
    while(temp)
    {
        if(temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}
int main()
{
    //init array of list to NULL
   
  //intitalize();

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    display();
  if(search(10))
       printf("found\n");
  else
       printf("not found\n");

    return 0;
}