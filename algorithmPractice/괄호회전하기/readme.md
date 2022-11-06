## 아이디어 

괄호의 종류가 3개라서 스택을 사용해야겠다는 생각을 했다. 괄호가 맞는지 판단하는 알고리즘은 많이 해봤기에 바로 떠올릴 수 있었다. 그리고 회전시키면서 그 괄호열이 맞는지 판단하면 돼서 무난하게 풀었다.

```cpp

#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isRight(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.empty())return false;
            switch (st.top())
            {
            case '(':
                if (s[i] == ')')break;
                else return false;
            case '{':
                if (s[i] == '}')break;
                else return false;
            case '[':
                if (s[i] == ']')break;
                else return false;
            default:
                break;
            }
            st.pop();
        }
    }
    if (!st.empty())return false;
    return true;
}

int solution(string s) {
    int answer = 0;

    // s가 올바른 문자열인지 체크
    if (isRight(s) == true)answer++;

    for (int i = 1; i < s.length(); i++)
    {
        // i번 회전시켰을때 체크
        string d = s.substr(1)+s[0];
        s = d;
        if (isRight(s))answer++;
    }

    return answer;
}

int main()
{
    printf("%d", solution("{{{{{{"));
    return 0;
}

```