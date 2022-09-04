#include <string>
#include <vector>

using namespace std;

vector<unsigned int> solution(int n, int m) {
    vector<unsigned int> answer;
    //�ִ����� = G
    //�ּҰ���� L = G * a * b;    

    //�ִ����� ���ϱ�
    unsigned int G = 1;
    int min = (n < m) ? n : m;
    for (int i = 1; i <= min; i++)
    {
        // ���⼭ G *= i ���� G = i �� �ٲ���� �ذ�Ǿ���. 
        // ���μ����ظ� �ϸ� ���� �� ���ϱ� ������ G*=i�� �߾��µ� 
        // �� �ڵ�� if���� ���� �������� ���̴�. ���� ���� ������ if���� �� ���� 
        // ����ϸ� �װ� �ִ� �������� ���̵ȴ�.
        // ���� ������ �߸� �����Ͽ���.
        // ���� ���а����� ���������� ��Ŭ���� ȣ�������� ��κ� Ǭ �� ����.
        if (n % i == 0 && m % i == 0)G = i;
    }
    unsigned int L = G * (n / G) * (m / G);

    answer.push_back(G);
    answer.push_back(L);
    return answer;
}
int main()
{
    solution(100000, 99999);
    return 0;
}