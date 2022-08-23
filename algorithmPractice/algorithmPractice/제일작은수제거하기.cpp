#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return (answer);
    }
    int min = 2100000000;

    for (int i : arr)
    {
        if (min > i)min = i;
    }
    for (int i : arr)
    {
        if (min == i)continue;
        answer.push_back(i);
    }

    return answer;
}
int main()
{
    
}