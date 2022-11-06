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

    // s�� �ùٸ� ���ڿ����� üũ
    if (isRight(s) == true)answer++;

    for (int i = 1; i < s.length(); i++)
    {
        // i�� ȸ���������� üũ
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