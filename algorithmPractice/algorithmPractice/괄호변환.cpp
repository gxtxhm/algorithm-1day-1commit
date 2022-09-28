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