## 아이디어 

처음에 n^n배열을 다 채운다음 잘라보니 시간초과가 났다. 시간을 줄여보고자 left에서 right까지의 수만 알아내서 저장하자는 생각을하였다. 
2개의 변수 row,col을 두고 n-1부터 n-n까지중 row나 col과 같은 수가 있다면 그 수가 arr[row][col]에 들어갈 수라고 판단하여 저장하였다. 하지만 
이렇게 하면 결국 이중포문이 되며 특정상황에서는 시간초과가 결국 나게 된다. 다른 방법이 있나 싶어서 검색을 해보니 안쪽포문을 돌 필요가 없었다. 
row,col중에 큰 수에 해당자리에 들어갈 수였다. 
이걸 왜 못알아차렸을까 싶다.

``` cpp

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long row = 0, col = 0;
    for (long long cnt = left; cnt <= right; cnt++)
    {
        row = cnt / (n);
        col = cnt % (n);

        answer.push_back(max(row,col)+1);
    }

    return answer;
}


```