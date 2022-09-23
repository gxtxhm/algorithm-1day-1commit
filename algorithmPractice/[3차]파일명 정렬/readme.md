## 아이디어

vector에 file명을 head,number,tail 3부분으로 나눠서 vector<string>으로 저장했다. (vector<vector<string>>)
그리고 head와 number를 기준으로 정렬했다.

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string s)
{
    vector<string>n;
    string a = "";
    int i = 0;
    for (i=0;i<s.length();i++)
    {
        if (isdigit(s[i]))
        {
            n.push_back(a);
            a = ""; break;
        }
        else
        {
            a += s[i];
        }
    }
    
    for (i; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {
            n.push_back(a);
            a = ""; break;
        }
        else
        {
            a += s[i];
        }
    }
    if (i == s.length())
    {
        n.push_back(a); n.push_back("");
    }
    else n.push_back(s.substr(i));
    return n;
}

bool comp(const vector<string>& a,const vector<string>& b)
{
    string ah = "";
    string bh = "";

    for (char c : a[0])
    {
        ah += tolower(c);
    }
    for (char c : b[0])
    {
        bh += tolower(c);
    }
    if (ah < bh)return true;
    else if (ah > bh)return false;
    else
    {
        int an = stoi(a[1]);
        int bn = stoi(b[1]);

        if (an < bn)return true;
        else return false;
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>>f;

    for (string s : files)
    {
        f.push_back(split(s));
    }
    //정렬
    stable_sort(f.begin(), f.end(), comp);

    for (auto s : f)
    {
        string r = "";
        r = s[0] + s[1] + s[2];
        answer.push_back(r);
    }

    return answer;
}

int main()
{
    vector<string> a = { "foo9.txt","foo010bar020.zip","F-15"};
    solution(a);
    return 0;
}

```

## 알게 된 것

sort함수는 불안정한 정렬이 된다고 한다. 
1,2,5,3,5 일때 5 두개의 순서가 바뀔수도 있다고한다. 그래서 처음에 
통과하지 못했었다. 
stable_sort 함수는 5 두개의 순서를 유지하면서 정렬을 한다.
이 함수를 사용해서 통과하였다.