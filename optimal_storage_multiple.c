#include<stdio.h>
#include<stdlib.h>


int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;

}

int optstorage(int arr[],int n)
{  int i,s=0;
  for(i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            s+=arr[j];
        }
    }

  return s;
}

int  multiple(int arr[],int n,int t)
{  int i,k;
   int tapes[t][(int)n/t+1];
   for(i=0;i<t;i++)
   {for(k=0;k<n/t+1;k++) 
      tapes[i][k]=0;
   }  
 

   k=-1;
  for(i=0;i<n;i++)
  {    if(i%t==0) 
          ++k;
     tapes[i%t][k]=arr[i];
  }
   int p=0;
   for(i=0;i<k;i++)
     {
        p+=optstorage(tapes[i],(n/t)+1);
     }
 return p;

}
int main ()
{ int arr[]={2,5,4,5,4,7,6,8,3,8};
  int n=10;
  int tot_tapes=3;
  qsort(arr,n,sizeof(int),compare);
  
printf("%d \n",multiple(arr,n,tot_tapes));
return 0;


}