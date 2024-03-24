#include<stdio.h>
#include<stdlib.h>

#define tablesize 10

int hashtable[tablesize];

int hashfunction(int key)
{
    return key%tablesize;
}



void insert(int key)
{ int index=hashfunction(key);
  while(hashtable[index]!=0)
  {  index=(index+1)%tablesize;

  }
hashtable[index]=key;



}
void display()
{ int i=0;
  printf("hashtable using linear probing is\n");
  for(i=0;i<tablesize;i++)
    printf("index[%d]=%d\n",i,hashtable[i]);
 


}
int search(int value)
{ int  i=hashfunction(value);
  while(hashtable[i]==value)
  { return 1;
   i=(i+1)%tablesize;
   

  }

}


int main()
{
    //init array of list to NULL
   
  //intitalize();

    insert(7);
    insert(20);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    display();

    return 0;
}
