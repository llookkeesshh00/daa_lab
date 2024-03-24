#include <stdio.h>
int min,max;

void min_max(int a[], int l, int h)
{    int max1,min1;
    if (l == h)
        max = min = a[l];
    else if (l == h - 1)
    {
        if (a[l] > a[h])
        {
            max = a[l];
            min = a[h];
        }
        else
        {
            max = a[h];
            min = a[l];
        }
    }
    else
    {
        int mid=(l+h)/2;
        min_max(a,l,mid);
         max1=max;
         min1=min;

        min_max(a,mid+1,h);

        if(max<max1) max=max1;
        if(min>min1) min=min1;
         
    }


    }


int main()
{
    int a[10] = {1, 3, 9, 11, 13, 15, 17,444, 21};
    int l = 0;
    int h = 8;
    min_max(a, l, h);
    printf("max=%d min=%d", max, min);
}