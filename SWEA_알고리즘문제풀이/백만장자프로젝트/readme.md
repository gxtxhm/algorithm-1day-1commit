## 아이디어

현재 남아있는 날짜 중 가장 비쌀때 팔고 나머지 날에는 전부 구매를 한다. 
그래서 팔 때마다 다시 max를 구한다.

```cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;


int main()
{
    int T;
    scanf("%d", &T);

    vector<int>arr;

    for (int i = 0; i < T; i++)
    {
        arr.clear();
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            int im;
            scanf("%d", &im);
            arr.push_back(im);
        }
        // arr에서 최대값을 찾아준다.
        int max = *max_element(arr.begin(), arr.end());
        int money = 0;
        int cnt = 0;
        long long profit = 0;
        vector<int>::iterator it;
        for (it=arr.begin();it!=arr.end();it++)
        {
            if (*it != max)
            {
                cnt++;
                money += *it;
            }
            else
            {
                if(cnt>0)profit += (cnt * max - money); 
                cnt = 0; money = 0;
                if(it+1!=arr.end())max = *max_element(it + 1, arr.end());
            }
        }
        printf("#%d %lld\n", i + 1, profit);
    }
    return 0;
}


```

## 배운 지식

vector에서 <algorithm>에 있는 max_element함수를 이용하면 max값을 구할 수 있다.
매개변수로 반복자 iterator가 필요하다. 

### iterator란 
일종의 포인터와 동일하다. iterator에 배열이나 벡터의 주소를 할당하고 +,- 연산자를 사용하여 
배열을 순회할 수 있다.