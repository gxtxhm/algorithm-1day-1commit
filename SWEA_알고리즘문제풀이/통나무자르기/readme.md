## 아이디어

경우의 수가 짝수일 때와 홀수일 때니까 짝수 몇개 홀수 몇개를 직접 해봤더니 짝수일때는 alice가 전부이기고
홀수일 때는 bob이 전부이겼다. 


```cpp

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

```
