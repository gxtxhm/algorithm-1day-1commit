using namespace std;

// 몇가지 케이스만 실패로 뜨길래 고민하다가 문득 return타입이 longlong인것을 깨달았다.
// 즉, 일부 케이스에서 int의 범위를 넘어섰기 때문일 것이라고 생각하여 타입을 바꾸었더니 해결되었다.

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