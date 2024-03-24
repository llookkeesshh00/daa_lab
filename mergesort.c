#include <stdio.h>

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
}

void merge(int *a, int mid, int low, int high)
{
    int c[50]; 
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = a[j];
            j++;
            k++;
        }
    }
    if (i <= mid)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    if (j <= high)
    {
        c[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}

void ms(int *a, int low, int high)
{   int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        ms(a, low, mid);
        ms(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[5] = {1, 4, 2, 36, 1};
    ms(a,0,4);
    printf("sorted aray is\n");
    display(a,5);
}