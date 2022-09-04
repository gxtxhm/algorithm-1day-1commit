#include <string>
#include <vector>

using namespace std;

vector<unsigned int> solution(int n, int m) {
    vector<unsigned int> answer;
    //최대공약수 = G
    //최소공배수 L = G * a * b;    

    //최대공약수 구하기
    unsigned int G = 1;
    int min = (n < m) ? n : m;
    for (int i = 1; i <= min; i++)
    {
        // 여기서 G *= i 에서 G = i 로 바꿨더니 해결되었다. 
        // 소인수분해를 하면 수를 다 곱하기 때문에 G*=i로 했었는데 
        // 이 코드는 if문에 들어가면 공약수라는 뜻이다. 따라서 가장 마지막 if문에 들어간 수만 
        // 기억하면 그게 최대 공약수라는 뜻이된다.
        // 수학 공식을 잘못 적용하였다.
        // 나는 수학공식을 적용했지만 유클리드 호제법으로 대부분 푼 것 같다.
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