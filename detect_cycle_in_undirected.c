int N  = 7;
int graph[7][7] = {{0,1,1,0,1,0,0},
                     {1,0,1,1,0,0,0},
                     {1,1,0,1,1,0,0},
                     {0,1,1,0,1,0,0},
                     {1,0,1,1,0,1,1},
                     {0,0,0,0,1,1,0}};

int bfs(int start,int visited[])
{
    int queue[N],front=-1,rear=-1;
    visited[start]=0;
    queue[++rear]=start;
    front++;

    while(front<=rear)
    { int ele=queue[front++];
    //condition after deleting the element
      
      visited[ele]=1;

    //   printf("%d ",ele);
      for(int i=0;i<N;i++)
      {  if(graph[ele][i]!=0 && visited[i]==0)
        {   return 1;
            
        }
         if(graph[ele][i]!=0 && visited[i]==-1)
         {
            queue[++rear]=i;
            visited[i]=0;
         }
      }
        
    }
    return 0;
}



void dfs(int visited[],int start)
{  
     printf(" %d ",start);
     visited[start]=1;

    for(int i=0;i<N;i++)
{  if(graph[start][i]==1 && visited[i]==0)
    {
        dfs(visited,i);
         }

}


}
int main()
{   int visited[N];
   for(int i=0;i<N;i++) visited[i]=-1;

   printf("%d ",bfs(0,visited));

    // defining the number of total persons 
   
}