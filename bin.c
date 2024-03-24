#include<stdio.h>

int binary_search(int A[], int key, int l,int h) {
  
  

  while (l <= h) {
    int mid = (l + h)/2;

    if (A[mid] == key) {
      return mid;
    }

    if (key < A[mid]) {
      return binary_search(A,key,l,mid-1);
    }
    else {
           return binary_search(A,key,mid+1,h);

    }
  }
  return -1;
}

int main() {
  int a[10]={1,3,5,7,9,11,13,15,17,21};
  int key = 39;

  int position = binary_search(a, key, 0,9);
  if (position == -1){
    printf("Not found");
    return 0;
  }
  printf("Found it at %d", position);
  return 0;
}