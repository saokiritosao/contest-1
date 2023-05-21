#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long

typedef struct Stack
{
    int *yk;
    int last;
} Stack;

int mn = 1e9, x, n, k, kk, y, q;

Stack* stack_ctr(int size, int element_size)
{
    Stack* neww = NULL;
    neww = (Stack* )malloc(sizeof(Stack));
    neww->yk = (int* )malloc(size* element_size);
    neww->last = 0;
    return neww;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int min(int a, int b)
{
    if(a > b)
        return b;
    else return a;
}

void enqueue(Stack *st, int x)
{
    st->yk[st->last] = x;
    st->last++;
    return ;
}

void dequeue(Stack *st)
{
    if(st->last == 0)
    {
        printf("error\n");
        return ;
    }
    printf("%d\n", st->yk[st->last - 1]);
    st->last--;
    return ;
}

void front(Stack *st)
{
    if(st->last == 0)
    {
        printf("error\n");
        return ;
    }
    printf("%d\n", st->yk[st->last - 1]);
    return ;
}

void size(Stack *st)
{
    printf("%d\n", y - q + st->last);
    return ;
}

void clear(Stack* st)
{
    st->last = 0;
    st = NULL;
    q = y = 0;
    mn = 1e9;
    printf("ok\n");
    return ;
}

void mini(Stack *st, int *pref)
{
    if(st->last == 0)
    {
        if(mn == 1e9)
        {
            printf("error\n");
        }
        else printf("%d\n", mn);
        return ;
    }
    printf("%d\n", min(mn, pref[st->last - 1]));
}

int main()
{
    int z = scanf("%d", &n);
    z /= z;
    int *pref = malloc(n * sizeof(int));
    int *a = malloc(n * sizeof(int));
    Stack *st = stack_ctr(200001, sizeof(int));
    for(int i = 1; i <= n; i++)
    {
        char s[30];
        z = scanf("%s", s);
        z /= z;
        if(s[0] == 'e')
        {
            z = scanf("%d", &a[y++]);
            z /= z;
            mn = min(mn, a[y - 1]);
            printf("ok\n");
        }
        if(s[0] == 'd')
        {
            if(st->last == 0)
            {
                mn = 1e9;
                for(int j = y - 1; j >= q; j--)
                {
                    enqueue(st, a[j]);
                }
                pref[0] = st->yk[0];
                for(int j = 1; j < st->last; j++)
                    pref[j] = min(pref[j - 1], st->yk[j]);
                q = y;
            }
            dequeue(st);
            if(st->last == 0)
            {
                mn = 1e9;
                for(int j = y - 1; j >= q; j--)
                {
                    enqueue(st, a[j]);
                }
                pref[0] = st->yk[0];
                for(int j = 1; j < st->last; j++)
                    pref[j] = min(pref[j - 1], st->yk[j]);
                q = y;
            }
        }
        if(s[0] == 'f')
        {
            if(st->last == 0)
            {
                mn = 1e9;
                for(int j = y - 1; j >= q; j--)
                {
                    enqueue(st, a[j]);
                }
                pref[0] = st->yk[0];
                for(int j = 1; j < st->last; j++)
                    pref[j] = min(pref[j - 1], st->yk[j]);
                q = y;
            }
            front(st);
        }
        if(s[0] == 's')
        {
            size(st);
        }
        if(s[0] == 'c')
        {
            clear(st);
        }
        if(s[0] == 'm')
        {
            mini(st, pref);
        }
    }
    return 0;
}
/**
**/
