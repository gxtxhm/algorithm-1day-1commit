## 아이디어 

처음에 푼 방식은 중간에 방향을 꺾는 것을 생각하지 않아서 테스트케이스 중 절반은 틀렸다. 구글링을 해보니 수학식으로 문제를 풀었던데 이해가 잘 가지않는다.
2a*b는 0->i->0->index로 가고, 
a+2*b는 0->index->0->i로 가는 경로이다.

```cpp

#include <string>
#include <vector>
using namespace std;

// 그리디알고리즘 : 현재상황에 대한 최적해를 구하는 알고리즘.
// 그리디를 사용했을 때 최적해가 나온다는 보장이 있어야함.


int solution(string name) {
    int answer = 0;

    int i = 0;// A = 0 , Z = 25;
    int n = name.length();
    int turn = n - 1;


    for(int i=0;i<n;i++)
    {
        // 조이스틱으로 이동하는 수를 먼저 더함
        if (name[i]-'A'<14)
        {
            answer += name[i] - 'A';
        }
        else
        {
            answer += 'Z' - name[i] + 1;
        }
        int index = i + 1;
        while (index < n && name[index] == 'A')index++;
        
        int a = i;
        int b = n - index;

        turn = min(turn, min(2 * a + b, 2 * b + a));

    }
    answer += turn;
    return answer;
}



```