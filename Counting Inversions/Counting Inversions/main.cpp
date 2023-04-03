#include <iostream>

int sort_and_count(int a[], int l, int r);


int sort_and_count(int a[], int l, int r) {
  if (l == r) {
    return 0;
  } else {
    int mid = (l+r)/2;
    int first = sort_and_count(a, l, mid);
    int second = sort_and_count(a, mid+1, r);

    int i=l;
    int j=mid+1;
    int k=0;
    int output[r-l+1];
    int inversion=0;

    while (i <= mid && j <= r) {
       if (a[i] <= a[j]) {
         output[k++] = a[i++];
       } else {
         output[k++] = a[j++];
         inversion += (mid-i)+1;
       }
    }
    while (i <= mid) {
       output[k++] = a[i++];
    }
    while (j <= r) {
       output[k++] = a[j++];
    }

    k=0;
    for (int i = l; i <= r; i++) {
      a[i] = output[k++];
    }
    return inversion + first + second;
  }
}

int main(int argc, const char *argv[])
{
  int a[] = {1,3,5,2,4,6};
  int len = sizeof(a)/sizeof(int);
  int in = sort_and_count(a, 0, len-1);
    std::cout << "inversions count: %d\n" << in;
  return 0;
}
