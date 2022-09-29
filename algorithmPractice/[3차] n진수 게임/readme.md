## 아이디어 

t*m 까지의 수를 전부 진수변환을 통해 문자열로 미리 저장해놓는다. 
그리고 문자열에서 튜브가 대답해야할 문자를 for문을 통해서 찾아냈다.

```cpp

#include <string>
#include <vector>

using namespace std;

char table[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string convert(int num,int n)
{
    if (num == 0)return "0";
    string a = "";
    while (num > 0)
    {
        int s = num % n;
        a += table[s];
        num /= n;
    }
    reverse(a.begin(), a.end());
    return a;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string result = "";

    // 미리 숫자 구하기
    for (int i = 0; i <= t*m; i++)
    {
        result += convert(i,n);
    }
    int cnt = 0;
    for (int i = p - 1; cnt < t; cnt++, i += m)answer += result[i];

    return answer;
}

int main()
{
    solution(16,16, 2, 1);
    return 0;
}

```