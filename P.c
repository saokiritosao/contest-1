#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long

ll a[1000010], q, c[1000010], b[1000010];
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

void nind(int i)
{
    b[c[i]] = i;
    return;
}

void sift_down(int i)
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
                nind(i);
                nind(l);
                i = l;
            }
            else
            {
                swap(&a[i], &a[r]);
                swap(&c[i], &c[r]);
                nind(i);
                nind(r);
                i = r;
            }
        }
        else break;
    }
    return ;
}

void sift_up(int i)
{
    while(i > 1 && a[i] < a[i / 2])
    {
        swap(&a[i], &a[i / 2]);
        swap(&c[i], &c[i / 2]);
        nind(i);
        nind(i / 2);
        i = i / 2;
    }
    return ;
}

void getmin()
{
    printf("%lld\n", a[1]);
}

void extract_min()
{
    swap(&a[1], &a[k]);
    swap(&c[1], &c[k--]);
    nind(1);
    nind(k + 1);
    sift_down(1);
}

void decreasekey(int x, int y)
{
//    printf("\n");
    a[b[x]] -= y;
    sift_up(b[x]);
}

int main()
{
    int z = scanf("%d", &n);
    z /= z;
    for(int i = 1; i <= n; i++)
    {
        char s[30];
        z = scanf("%s", s);
        z /= z;
        if(s[0] == 'i')
        {
            int x;
            z = scanf("%d", &x);
            z /= z;
            a[++k] = x;
            c[k] = i;
            nind(k);
            sift_up(k);
        }
        if(s[0] == 'g')
        {
            getmin();
        }
        if(s[0] == 'e')
        {
            extract_min();
        }
        if(s[0] == 'd')
        {
            int x, y;
            z = scanf("%d%d", &x, &y);
            z /= z;
            decreasekey(x, y);
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
