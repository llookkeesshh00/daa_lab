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


int main ()
{ int arr[]={2,5,4};
  int n=3;
  qsort(arr,n,sizeof(int),compare);
  for(int i=0;i<n;i++)
   printf("%d ",arr[i]);

 printf("total storage is %d\n",optstorage(arr,n));
 printf("mean retrival time is %f\n",optstorage(arr,n)/(double)n);


}