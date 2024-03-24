#include <stdio.h>

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
}


int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int a[], int low, int high)
{
    int paritionindex;
    if (low < high)
    {
        paritionindex = partition(a, low, high);
        quicksort(a, low, paritionindex - 1);
        quicksort(a, paritionindex + 1, high);
    }
}

int main()
{
    int a[] = {100, 88, 70, 42, 6, 5};
    int n = 6;
    printf("array before sorting\n");
    display(a, n);
    printf("\n array after sorting\n");
    quicksort(a, 0, n - 1);
    display(a, n);
}