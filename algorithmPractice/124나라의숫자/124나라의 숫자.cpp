#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    int arr[20]={0,};
    int cnt = 3;
    arr[0] = 1;
    for (int i = 1; i < 20; i++){arr[i] = arr[i-1]+cnt; cnt *= 3;}

    int pn = 1;
    int i = 0;
    // n이 어디에 포함되는지
    while (true)
    {
        if (n >= arr[i] && n < arr[i + 1])break;
        i++;
    }
    int s = arr[i + 1] - arr[i];
    s /= 3;

    string con;
    int stid = 0;
    for (int j = 0; j <= i; j++)con += "1";
    // -- 124로 표현했을 때 자릿수가 몇개인지까지 파악. --

    string id = "124";
    int an = arr[i];
    
    while (true)
    {
        if (an == n)break;
        int it = 0;
        for ( it = 0; it < 3; it++)
        {
            if (an + s * (it + 1) > n && an+s*it <= n)
            {
                an += s * it;
                break;
            }
        }
        con[stid] = id[it];
        stid++;
        s /= 3;

    }

    return con;
}

int main()
{
    solution(38);
    return 0;
}