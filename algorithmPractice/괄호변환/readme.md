## 아이디어 

매개변수 string p를 균형잡힌 문자열  u와 나머지 v로 나눠서 제시된 방법으로 변환 과정을 적용한다. 이 때, v에 대해 재귀적으로 과정을 적용시킨다.

```cpp

#include <string>
#include <vector>

using namespace std;

// 제일 작은 균형잡힌 문자열 u와 v로 나눠서 리턴한다.
vector<string> slice(string s)
{
    vector<string>ss;
    int cnt = 0;

    if (s[0] == '(')cnt++;
    if (s[0] == ')')cnt--;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '(')cnt++;
        if (s[i] == ')')cnt--;
        if (cnt == 0)//균형잡힌 문자열이 된 것.
        {
            string u = s.substr(0, i + 1);
            ss.push_back(u);
            string v = s.substr(i + 1);
            ss.push_back(v);
            return ss;
        }
    }
}
// 올바른 문자열인지 확인한다.
bool CheckRight(string s)
{
    int cnt = 0;
    for (char c : s)
    {
        if (c == '(')cnt++;
        if (c == ')')cnt--;
        if (cnt < 0)return false;
    }
    return true;
}

string solution(string p) {

    string answer = "";

    if (p == "")return answer;

    if (CheckRight(p))return p;
    vector<string> slice_string= slice(p);
    

    // u가 올바른 괄호 문자열이라면 v에 대해 slice
    if (CheckRight(slice_string[0]))
    {
        answer = slice_string[0] + solution(slice_string[1]);
    }
    else
    {
        answer = "(" + solution(slice_string[1]) + ")";
        for (int i = 1; i < slice_string[0].length() - 1; ++i) 
            answer += slice_string[0][i] == '(' ? ')' : '(';
    }
    // 아니라면 

    return answer;
}

int main()
{
    solution("()");

    return 0;
}


```

## 아쉬운 점
 
문제를 30분정도 봐도 이해가 잘 가지 않아서 답을 보았다. 
이해가 바로 안됐던 이유는 재귀적인 사고방식에 대해 아직 미숙하기 때문이라는 생각이 든다. answer = u + solution(v)에 대한 생각이 안떠올라서 이 문제를 해결하지 못했던 것 같다. 1~2일의 시간을 두고 다시 풀어봐야겠다.