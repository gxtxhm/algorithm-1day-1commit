## 아이디어 

자연수를 1부터 쭉 124나라의 숫자로 변환하다보니 규칙이 보였다. 자릿수가 늘어날때가 처음엔 자연수 +3이 되었을때였고 그다음엔 +9되었을 때였다. 
이 규칙을 이용하자는 생각으로 배열에 arr[i]=arr[i-1]+3의배수를 넣었다. 5천만이하까지

38을 찾으려면 먼저 자릿수를 찾는다. arr[i]가 1씩 증가할 때마다 자릿수가 하나씩 증가한다.
arr={1,4,13,40...}
13<=38<=40 이다.  그러면 이제부터는 각 자릿수마다 1,2,4중 하나를 선택하면 된다. 이때도 13과40의 차이인 27을 이용한다. 27/3=9는 첫번째 자릿수의 숫자가 변하는 기준이다. 13과 13+9사이에 n이 있다면 그 숫자는 1xx일 것이다.  이런식으로 n을 찾았다. 

```cpp


#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    int arr[20]={0,};
    int cnt = 3;
    arr[0] = 1;
    for (int i = 1; i < 20; i++){arr[i] = arr[i-1]+cnt; cnt *= 3;}

    int pn = 1;
    int i = 0;
    // n이 어디에 포함되는지
    while (true)
    {
        if (n >= arr[i] && n < arr[i + 1])break;
        i++;
    }
    int s = arr[i + 1] - arr[i];
    s /= 3;

    string con;
    int stid = 0;
    for (int j = 0; j <= i; j++)con += "1";
    // -- 124로 표현했을 때 자릿수가 몇개인지까지 파악. --

    string id = "124";
    int an = arr[i];
    
    while (true)
    {
        if (an == n)break;
        int it = 0;
        for ( it = 0; it < 3; it++)
        {
            if (an + s * (it + 1) > n && an+s*it <= n)
            {
                // 해당 자릿수의 알맞는 숫자를 찾음. 1,2,4 중 결정
                an += s * it;
                break;
            }
        }
        // 결정된 숫자로 문자열 변경
        con[stid] = id[it];
        // 하나 아래의 자릿수를 판단하기위한 변수증가
        stid++;
        s /= 3;

    }

    return con;
}

int main()
{
    solution(38);
    return 0;
}

```