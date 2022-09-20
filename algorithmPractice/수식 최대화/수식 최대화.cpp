#include <string>
#include <vector>


using namespace std;

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

    for (string c : cases)
    {
        arr = arr2;
        oper = oper2;
        for (char op : c)
        {
            int id ;
            while ((id= findOP(oper, op) )!=oper.size())
            {
                long long value=0;
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
                oper.erase(find(oper.begin(),oper.end(),op));
                arr[id] = value;
                arr.erase(arr.begin() + (id+1));
            }
        }
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