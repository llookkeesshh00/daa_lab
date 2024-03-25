 #include<stdio.h>
 int n=4;
 int adj[4][4]={{0,3,1,0},{3,0,2,4},{1,2,0,5},{0,4,5,0}};
 
 int mindist[4];
 int parent[4];
 int visited[4];

 int select_min_node()
{ int min=10000;
 int ind,i;
  for(i=0;i<n;i++)
    {
        if(mindist[i]<min && visited[i]==0)
           { min=mindist[i];
             ind=i;

           }
    }
    return ind;

}

void prims(int source)
{  int i,j;
   for(i=0;i<n;i++) mindist[i]=10000;
 
  mindist[source]=0;
  //need to run this for n-1 edges
   for(i=0;i<n-1;i++)
   {
     visited[source]=1; 
    
      for(j=0;j<n;j++)
     { if(visited[j]==0 && adj[source][j]>0  && mindist[j]>adj[source][j])
         { mindist[j]=adj[source][j];
           parent[j]=source;

         }

     }
   source=select_min_node();

   }
 


}
int main()
{  int k=n,t=1;
   prims(3);
  
  for(int i=0;i<n;i++)
    printf("%d ",mindist[i]);
 

  for(int i=0;i<n;i++)
    printf("%d ",parent[i]);
  

    
 while(k!=0)
 { printf("%d-->",t);
   t=parent[t];
   k--;
 }


}