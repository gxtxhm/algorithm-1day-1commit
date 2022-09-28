#include <string>
#include <vector>

using namespace std;

// ���� ���� �������� ���ڿ� u�� v�� ������ �����Ѵ�.
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
        if (cnt == 0)//�������� ���ڿ��� �� ��.
        {
            string u = s.substr(0, i + 1);
            ss.push_back(u);
            string v = s.substr(i + 1);
            ss.push_back(v);
            return ss;
        }
    }
}
// �ùٸ� ���ڿ����� Ȯ���Ѵ�.
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
    

    // u�� �ùٸ� ��ȣ ���ڿ��̶�� v�� ���� slice
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
    // �ƴ϶�� 

    return answer;
}

int main()
{
    solution("()");

    return 0;
}