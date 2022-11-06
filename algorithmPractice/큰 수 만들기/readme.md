## 아이디어 

해결법이 떠오르지 않아서 구글링하여 답을 보았다. 
n개 자리의 숫자 중 k개를 뺀 나머지가 답의 자리수이다. 따라서 n-k까지만 먼저 포문을 돈다.
그리고 그 안에서 첫번째 포문의 인덱스를 기준으로 k개씩 확인한다. 그리고 그중 가장 큰 수를 골라서 답에 저장한다. 앞자리의 수가 클수록 숫자가 커지기 때문이다. 그리고 인덱스를 따로 저장하여 그 인덱스부터 검색하기 때문에 중복되지 않는다.


그리디 문제가 아직 익숙하지 않은건지 그리디문제를 어떤식으로 접근해야할지 명확하게 알지는 못하겠다.
```cpp

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int n = number.length() - k;

    for (int i = 0, idx = -1; i < n; i++) {
        char max = '0';
        for (int j = idx + 1; j <= k + i; j++) {
            if (max < number[j]) {
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