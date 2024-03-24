#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double weight;
    double profit;
} item;

int compare(const void *a, const void *b)
{
    double b1 = ((item *)b)->profit /((item *)b)->weight;
    double a1 = ((item *)a)->profit /((item *)a)->weight;
    return b1 - a1;
}
double fractional(int capacity, item it[], int n)
{
    qsort(it, n, sizeof(item), compare);
    double res = 0;
    for (int i = 0; i < n; i++)
    {  
        if (capacity > it[i].weight)
        {
            res += it[i].profit;
            capacity -= it[i].weight;
        }

        else
        {res+=it[i].profit/it[i].weight*capacity;
        break;
        }

    }
    return res;
}

int main()
{ int c=50;
 item it[]={{10,50},{40,100},{30,120}};
  int n=3;
  printf("max profit=%f\n",fractional(c,it,n));

}