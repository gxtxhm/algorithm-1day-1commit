using namespace std;

// ��� ���̽��� ���з� �߱淡 ����ϴٰ� ���� returnŸ���� longlong�ΰ��� ���޾Ҵ�.
// ��, �Ϻ� ���̽����� int�� ������ �Ѿ�� ������ ���̶�� �����Ͽ� Ÿ���� �ٲپ����� �ذ�Ǿ���.

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long sum = 0;
    for (int i = 1; i <= count; i++)
    {
        sum += price * i;
    }
    if (money - sum < 0)answer = -1 * (money - sum);
    else answer = 0;
    return answer;
}
int main()
{
    solution(1, 10, 6);
    return 0;
}