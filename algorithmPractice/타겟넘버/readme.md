## 아이디어

문제를 보고 바로 재귀함수를 떠올렸다.
수 하나하나를 더하고 뺐을때의 모든 경우의 수를 확인해야하기 때문이다.

```cpp

#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void recur(int index,vector<int>&numbers,int target,int curNum)
{
    if (index==numbers.size())
    {
        if(target == curNum)cnt++;
        return;
    }
    recur(index + 1, numbers, target, curNum + numbers[index]);
    recur(index + 1, numbers, target, curNum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    recur(0,numbers, target, 0);
    return cnt;
}
int main()
{
    vector<int> a = { 1,1,1,1,1 };
    solution(a, 3);
    return 0;
}


```