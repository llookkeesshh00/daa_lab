#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int profit;
    int deadline;
} item;

int compare(const void *a, const void *b)
{ // decreasing order of profit
    int b1 = ((item *)b)->profit;
    int a1 = ((item *)a)->profit;
    return b1 - a1;
}

int maxdeadline(item job[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < job[i].deadline)
            max = job[i].deadline;
    }
}

int maxprofit(item job[], int n)
{
    int k, p = 0, j;
    int maxdead = maxdeadline(job, n);
    qsort(job, n, sizeof(item), compare);
    int check[maxdead + 1];
    for (int i = 1; i <= maxdead; i++)
        check[i] = -1;

    for (int i = 0; i < n; i++)
    {
        k = job[i].deadline;
        for (j = k; j >= 1; j--)
        {
            if (check[j] == -1)
            {
                p += job[i].profit;
                printf("%d\n",  job[i].profit);
                check[j] = 0;
                break;
            }
        }
    }
    return p;
}
int main()
{
    item job[] = {{20, 2}, {15, 2}, {10, 1}, {5, 3}, {1, 3}};
    int n = 5;
    printf("max profit=%d\n", maxprofit(job, n));
}