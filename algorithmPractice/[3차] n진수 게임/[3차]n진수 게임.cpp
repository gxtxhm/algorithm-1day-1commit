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