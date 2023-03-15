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
    int size;
    int last;
} Stack;

Stack* stack_ctr(int size, int element_size)
{
    Stack* neww = NULL;
    neww = (Stack* )malloc(sizeof(Stack));
    if(neww == NULL)
    {
        exit(-1);
    }
    neww->size = size;
    neww->yk = (int* )malloc(neww->size* element_size);
    if(neww->yk == NULL)
    {
        free(neww);
        exit(-1);
    }
    neww->last = 0;
    return neww;
}

void clear(Stack* st)
{
    st->last = 0;
    st = NULL;
    printf("ok\n");
    return ;
}

void push(Stack* st, int n)
{
    if(st->last == st->size)
        return ;
    st->yk[st->last] = n;
    st->last++;
    printf("ok\n");
    return ;
}

void pop(Stack* st)
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

void last(Stack* st)
{
    if(st->last == 0)
    {
        printf("error\n");
        return ;
    }
    printf("%d\n", st->yk[st->last - 1]);
}

void size(Stack *st)
{
    printf("%d\n", st->last);
    return ;
}

void ext()
{
    printf("bye");
    exit(0);
}

int main()
{
    Stack *st = stack_ctr(10001, sizeof(int));
    //asd
    while(1 > 0)
    {
        char s[10];
        int x = scanf("%s", s);
        x /= x;
        if(s[0] == 'p' && s[1] == 'u')
        {
            int a;
            int x = scanf("%d", &a);
            a *= x;
            push(st, a);
        }
        else
        {
            if(s[0] == 'p')
            {
                pop(st);
            }
            else
            {
                if(s[0] == 'b')
                {
                    last(st);
                }
                else
                    if(s[0] == 's')
                    {
                        size(st);
                    }
                    else
                        if(s[0] == 'c')
                        {
                            clear(st);
                        }
                        else ext();
            }
        }
    }
    return 0;
}
