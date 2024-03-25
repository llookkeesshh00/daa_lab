#include <stdio.h>

int stack[20];
int top = -1;
int N = 4;
int graph[4][4] = {{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,1,0,0}};

int indegree(int v)
{
    int c=0;
   for(int i=0;i<N;i++)
     {
        if(graph[i][v]==1)
          c+=1;
  }
  return c;
}  
int reset(int v)
{
    int c=0;
   for(int i=0;i<N;i++)
     {
        graph[v][i]=0;
    }
  return c;
}  

void toposort()
{   int visited[N];
    int i,j;
    for (int i = 0; i < N; i++)
        visited[i] = 0;
    for(j=0;j<N;j++)
   { 
   for(i=0;i<N;i++)
   { if(visited[i]==0 && indegree(i)==0 )
       {
        reset(i);
        visited[i]=1;
        stack[++top]=i;
       }


   }}

}



int main()
{ toposort();
    //if no of elelemts in the stack is less than no of vertices

    for(int i=top;i>=0;i--)
    {
      printf("%d ",stack[i]);
    } 
    printf("%d ",top)
  ;
    return 0;
}