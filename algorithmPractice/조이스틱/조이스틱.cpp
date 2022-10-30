#include <string>
#include <vector>
using namespace std;

// �׸���˰��� : �����Ȳ�� ���� �����ظ� ���ϴ� �˰���.
// �׸��� ������� �� �����ذ� ���´ٴ� ������ �־����.


int solution(string name) {
    int answer = 0;

    int i = 0;// A = 0 , Z = 25;
    int n = name.length();
    int turn = n - 1;


    for(int i=0;i<n;i++)
    {
        // ���̽�ƽ���� �̵��ϴ� ���� ���� ����
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