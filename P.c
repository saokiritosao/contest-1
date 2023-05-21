#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long

const int N = 1000010;

ll q;
int x, y, n, k, kk;

void swap(ll *a, ll *b)
{
    ll c = *a;
    *a = *b;
    *b = c;
}


ll min(ll a, ll b)
{
    if(a > b)
        return b;
    else return a;
}

void nind(int i, int *b, int *c)
{
    b[c[i]] = i;
    return;
}

void sift_down(int i, int *a, int *b, int *c)
{
    int l, r;
    while(i <= k)
    {
        l = i * 2;
        r = l + 1;
        if (l > k) l = i;
        if (r > k) r = l;

        if (a[i] > min(a[l], a[r]))
        {
            if (a[l] <= a[r])
            {
                swap(&a[i], &a[l]);
                swap(&c[i], &c[l]);
                nind(i, b, c);
                nind(l, b, c);
                i = l;
            }
            else
            {
                swap(&a[i], &a[r]);
                swap(&c[i], &c[r]);
                nind(i, b, c);
                nind(r, b, c);
                i = r;
            }
        }
        else break;
    }
    return ;
}

void sift_up(int i, int *a, int *b, int *c)
{
    while(i > 1 && a[i] < a[i / 2])
    {
        swap(&a[i], &a[i / 2]);
        swap(&c[i], &c[i / 2]);
        nind(i, b, c);
        nind(i / 2, b, c);
        i = i / 2;
    }
    return ;
}

void getmin(int *a)
{
    printf("%lld\n", a[1]);
}

void extract_min(int *a, int *b, int *c)
{
    swap(&a[1], &a[k]);
    swap(&c[1], &c[k--]);
    nind(1, b, c);
    nind(k + 1, b, c);
    sift_down(1, a, b, c);
}

void decreasekey(int x, int y, int *a, int *b, int *c)
{
//    printf("\n");
    a[b[x]] -= y;
    sift_up(b[x], a, b, c);
}

int main()
{
    int z = scanf("%d", &n);
    z /= z;
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *c = malloc(n * sizeof(int));
    for(int i = 1; i <= n; i++)
    {
        char s[30];
        z = scanf("%4s", s);
        z /= z;
        if(s[0] == 'i')
        {
            int x;
            z = scanf("%d", &x);
            z /= z;
            a[++k] = x;
            c[k] = i;
            nind(k, b, c);
            sift_up(k, a, b, c);
        }
        if(s[0] == 'g')
        {
            getmin(a);
        }
        if(s[0] == 'e')
        {
            extract_min(a, b, c);
        }
        if(s[0] == 'd')
        {
            int x, y;
            z = scanf("%d%d", &x, &y);
            z /= z;
            decreasekey(x, y, a, b, c);
        }
    }
    return 0;
}
/**
17
i 3
i 4
i 1
e
g
d 1 2
g
d 2 4
g
i -1
g
d 1 2
g
d 10 4
g
d 10 20
g
-19
**/
