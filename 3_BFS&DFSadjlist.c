#include<stdio.h>
#include<stdlib.h>


struct node
{   int data;
    struct node * next;
};

struct node *adj[20];

struct node * create(int data)
{ struct node * new =(struct node *)malloc(sizeof(struct node*));
  new->data=data;
  new->next=NULL;
  return new;

}



void readgraph(int v)
{  int i,n,k,val;
   struct node *t;
   i=0;
  for(i=0;i<v;i++)
  {  
    printf("how many vertices adjacnet to vertex %d::",i);
    scanf("%d",&n);
    printf("how those nodes\n");
    for(k=0;k<n;k++)
    {  
      scanf("%d",&val);
      if(adj[i]==NULL)
         {
             adj[i]=create(val);
             t=adj[i];
         }
         else{
            t->next=create(val);
            t=t->next;
         }


    }
         
  }



}

void printgraph(int v)
{
	struct node *ptr  = NULL;
	int i,j;
	for(i=0;i<v;i++)
	{
		ptr = adj[i];
		printf("\n The neighbour of %d are :",i);
		while(ptr != NULL)
		{
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
	}
}
void bfs(int v,int start)
{  
    
    int i,ele;
    struct node *t;
    int visited[v];
    for(i=0;i<v;i++)  visited[i]=0;
     
// adding 1st element to the queue
    int queue[v],front=-1,rear=-1;
    visited[start]=1;
    queue[++rear]=start;
    front++;
  
  while(front<=rear)
  {  //deleting the 1st element from queue

    ele=queue[front++];
     t=adj[ele];
     printf("%d ",ele);
     
     while (t!=NULL)
     {

      if (visited[t->data]!=1)
     {
        queue[++rear]=t->data;
        visited[t->data]=1;

     }
     t=t->next;

  }
  
  }


printf("\n");
}


void dfs(int v,int start,int visited[])
{ visited[start]=1;
  printf("%d ",start);
  struct node *t=adj[start];

  while(t!=NULL)
  {  if(visited[t->data]!=1)
         dfs(v,t->data,visited);
    t=t->next;
  }


}

int main()
{  int i;
   int v;

   printf("enter the no of vertices\n");
   scanf("%d",&v);

   int visited[v];
  

   readgraph(v);
   printgraph(v);
   
   printf("BFS : ");
   bfs(v,0);
   
   printf("DFS : ");
   dfs(v,0,visited);

  return 0;
  


}
