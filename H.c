#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long
int k, n;
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
void qqsort(int b, int e, int *a)
{
    int l = b, r = e;
    int piv = a[(l + r) / 2];
    while(l <= r)
    {
        while(a[l] < piv)
            l++;
        while(a[r] > piv)
            r--;
        if(l <= r)
            swap(&a[l++], &a[r--]);
    }
//    printf("%d %d\n", l, r);
    if(b < r && k <= r)
        qqsort(b, r, a);
    else if(e > l && k >= l)
    {
        qqsort(l, e, a);
    }
}
int main()
{
    int x = scanf("%d%d", &n, &k);
    int *a = malloc(n * sizeof(int));
    scanf("%d%d", &a[1], &a[2]);
    n *= x/x;
    for(int i = 3; i <= n; i++)
    {
        a[i] = (a[i - 1] * 123 + a[i - 2] * 45) % (10000000 + 4321);
    }
    qqsort(1, n, a);
//    for(int i = 1; i <= n; i++)
//        printf("%d ", a[i]);
    printf("\n%d", a[k]);
//    qsort(a, n + 1, sizeof(int), cmp);
//    printf("\n%d", a[kk]);
    return 0;
}
