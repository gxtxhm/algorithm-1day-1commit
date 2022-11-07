## 해결 및 느낌 

해결법을 찾아보고 다음날 다시 풀어봤다. 전날 본거라 그런지 해결법은 바로 떠올랐다. 
그런데 다시 코드를 치다보니 그 의미를 좀 더 명확히 이해할 수 있었다.
먼저 number의 길이인 n에서 k개를 뺀 만큼의 문자가 answer에 저장된다.
즉, 답의 길이는 n-k이고 n-k개의 문자가 들어가야 하니까, for문을 n-k번 돌며 무언가를 추가한다.
1) i가 의미하는 것은 answer에 추가된 문자의 수와 같다. 
2) 일정범위를 검사하여 그 중 최선의 수를 찾아낸후 저장한다고 한다면, 뒤에 최소한의 n-k를 위한 숫자들을 남겨놓아야 한다. 그래서 i+k까지만 조사하는 것이다. i가 1씩 증가하면 즉, answer에 1개를 더 넣었다는 뜻으로 그 뒤에 1개만큼의 범위를 더 조사할 수 있게된다. 그리고 그 이전 범위 내에서 가장 큰 수를 넣었으니 그 뒤부터 탐색해야한다. 그게 idx가 가진 값이다. 
```cpp

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer="";

    int n = number.length();

    for (int i = 0, idx = -1; i < n - k; i++)
    {
        char max = '0';
        for (int j = idx + 1; j <= i + k; j++)
        {
            if (max < number[j])
            {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }

    return answer;
}

int main()
{
    solution("4177252841",4);
    return 0;
}

```