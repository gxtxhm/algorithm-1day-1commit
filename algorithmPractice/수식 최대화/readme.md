## 아이디어

처음엔 식을 후위표기법으로 바꾼 후 계산을 해야하나 생각을 했는데
너무 코드가 복잡해질 것 같아서 다시 생각해보니 연산자 3개로 나올 수 있는 6가지의
경우의 수를 미리 저장해놓은 다음 각 경우의 수에 따라 계산 후 최대값을 내는것이 낫겠다 싶어서 변경했다. 
그리고 식은 longlong리스트와 char리스트에 각각 숫자와 연산자를 구분하여 저장한다.
연산자 우선순위가 높은 index부터 차례로 계산해나가고 마지막 남은 숫자를 비교하여 답을 구한다.

```cpp

#include <string>
#include <vector>


using namespace std;

// 문자열을 숫자와 연산자리스트에 나눠서 저장해준다.
void split(string exp,vector<long long>&arr,vector<char>&oper) 
{
    string i = "";
    for (char c : exp)
    {
        if (c == '*' || c == '+' || c == '-')
        {
            arr.push_back(stoi(i));
            oper.push_back(c);
            i = "";
        }
        else
        {
            i += c;
        }
    }
    arr.push_back(stoi(i)); 
}
// op 연산자 중 제일 앞에 있는것을 찾아서 인덱스를 반환한다.
int findOP(vector<char>& oper, char op)
{
    for (int i=0;i<oper.size();i++)
    {
        if (oper[i] == op)
        {
            return i;
        }
    }
    return oper.size();
}

long long solution(string expression) {
    long long answer = 0;

    vector<string>cases = { "*+-","*-+","+*-","+-*","-*+","-+*" };

    vector<long long>arr;
    vector<long long>arr2;
    vector<char>oper;
    vector<char>oper2;
    long long max = -1;
    split(expression, arr2, oper2);

    // 모든 경우의 수를 살핀다.
    for (string c : cases)
    {
        arr = arr2;
        oper = oper2;
        // 각 경우의 수에서 연산자 우선순위가 높은 것부터 계산한다.
        for (char op : c)
        {
            int id ;
            // 해당 연산자가 없으면 다음 연산자로 넘어간다.
            // findOP함수로 연산자 인덱스를 찾고 
            while ((id= findOP(oper, op) )!=oper.size())
            {
                long long value=0;
                // 연산자에 해당하는 계산을 한다.
                switch (op)
                {
                case '*':
                    value = arr[id] * arr[id + 1]; break;
                case '+':
                    value = arr[id] + arr[id + 1]; break;
                case '-':
                    value = arr[id] - arr[id + 1]; break;
                default:
                    break;
                }
                // 계산된 연산자를 리스트에서 삭제한다.
                oper.erase(find(oper.begin(),oper.end(),op));
                // 마찬가지로 계산된 숫자 2개를 삭제하고 새로운 값을 대입한다.
                arr[id] = value;
                arr.erase(arr.begin() + (id+1));
            }
        }
        // 해당 경우의 수를 계산하고 결과를 비교한다.
        arr[0] = abs(arr[0]);
        max = (arr[0] > max) ? arr[0] : max;
    }
    return max;
}

int main()
{
    string a = "200-300-500-600*40+500+500";
    solution(a);
}

```