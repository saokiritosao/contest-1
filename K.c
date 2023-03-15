#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long
int a[100000 + 10], k, coa[100000 + 10], n;
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void qqsort(int b, int e)
{
  int l = b, r = e;
  int piv = a[abs(rand()) % (r - l) + l];
  while(l <= r)
  {
    while(a[l] < piv)
      l++;
    while(a[r] > piv)
      r--;
    if(l <= r)
      swap(&a[l++], &a[r--]);
  }
  if(b < r)
    qqsort(b, r);
  if(e > l)
    qqsort(l, e);
}
int main()
{
    int x = scanf("%d", &n);
    n *= x/x;
    for(int i = 1; i <= n; i++)
    {
        x = scanf("%d", &a[i]);
        a[i] *= x;
//        a[i] = (a[i - 1] * 123 + a[i - 2] * 45) % (10000000 + 4321);
//        printf("%d ", a[i]);
    }
    qqsort(1, n);
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
