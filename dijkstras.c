 #include<stdio.h>
 int n=4;
 int adj[4][4]={{0,3,0,5},{0,0,0,0},{0,2,0,0},{0,1,2,0}};

int visited[4];
int mindist[4];

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


void single_source_shortest(int s)
{ int i,j;
  for(i=0;i<n;i++) mindist[i]=10000;
 int source=s;
 
 mindist[source]=0;

 for(i=0;i<n;i++)
 { 
   printf(" %d",source);
    visited[source]=1; 
  for(j=0;j<n;j++)
    { if(visited[j]==0 && adj[source][j]>0  && mindist[j]>adj[source][j]+mindist[source])
        mindist[j]=adj[source][j]+mindist[source];
    }
  
  source=select_min_node();
 }
  




}

int main()
{ single_source_shortest(0);
  for(int i=0;i<n;i++)
    printf("\n%d ",mindist[i]);
    return 0;


}