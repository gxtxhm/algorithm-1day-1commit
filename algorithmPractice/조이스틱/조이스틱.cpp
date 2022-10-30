#include <string>
#include <vector>
using namespace std;

// 그리디알고리즘 : 현재상황에 대한 최적해를 구하는 알고리즘.
// 그리디를 사용했을 때 최적해가 나온다는 보장이 있어야함.


int solution(string name) {
    int answer = 0;

    int i = 0;// A = 0 , Z = 25;
    int n = name.length();
    int turn = n - 1;


    for(int i=0;i<n;i++)
    {
        // 조이스틱으로 이동하는 수를 먼저 더함
        if (name[i]-'A'<14)
        {
            answer += name[i] - 'A';
        }
        else
        {
            answer += 'Z' - name[i] + 1;
        }
        int index = i + 1;
        while (index < n && name[index] == 'A')index++;
        
        int a = i;
        int b = n - index;

        turn = min(turn, min(2 * a + b, 2 * b + a));

    }
    answer += turn;
    return answer;
}

int main()
{
    printf("%d",solution("ABAAAAAAAAABB"));
    return 0;
}