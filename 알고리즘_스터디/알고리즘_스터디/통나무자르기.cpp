#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int T;
    int i;
    int n;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &n);
        if (n % 2 == 0)printf("#%d Alice\n", i + 1);
        else printf("#%d Bob\n", i + 1);
    }

    return 0;
}