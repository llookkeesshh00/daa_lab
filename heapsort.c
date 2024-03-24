#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*b;
       *b=*a;
       *a=temp;
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
}


void heapify(int a[],int n, int i)
{ int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n && a[left]>a[largest]) 
     largest=left;
  if(right<n && a[right]>a[largest]) 
     largest=right;
if(largest!=i)
   { swap(&a[largest],&a[i]);
      heapify(a,n,largest);

   }
   
  return;


}


void heapsort(int a[],int n)
{ int i;
for(i=n/2-1 ;i>=0;i--)
     heapify(a,n,i);

for(i=n-1;i>=0;i--)
{  swap(&a[0],&a[i]);
   heapify(a,i,0);

}
}











int main()
{
    int a[] = {80,1, 23, 12, 6, 9, 10,2,4};
    int n = 9;
    printf("array before sorting\n");
    display(a, n);
    printf("\n array after sorting\n");
    heapsort(a,n);
    display(a, n);
}