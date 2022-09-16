## 아이디어

튜플을 집합기호로 표현했을 때, { }단위로 원소가 생성되기 때문에 
vector<string>에 { }단위로 문자열을 잘라서 저장한 후, 길이에 따라 정렬을 해야겠다는 생각을 했다. 왜냐하면 튜플을 집합기호로 생성할 때, 앞에 있는 숫자부터 원소로 만들어지기 때문이다.
ex) (3,1,2) 튜플일 때, {3},{1,3},{2,1,3} 이렇게 생성이 되기 때문에 
{ }단위로 slice한 문자열이 짧을 수록 튜플의 앞자리의 수이다. 
vector<string>을 for문으로 돌며 bool [1000001] 배열에 3부터 체크해나가면 튜플을 완성할 수 있다.

```cpp

#include <string>
#include <vector>
#include <algorithm>
#include<sstream>
using namespace std;

bool hash_table[100001] = { 0, };

bool compare(const string& a, const string& b)
{
    return a.length() <= b.length();
}


void slicingString(vector<string>& ss,const string& s)
{
    bool open = false;
    string i = "";
    for (char c : s)
    {
        if (c == '{')open = true;
        else if (c == '}')
        {
            open = false;
            ss.push_back(i);
            i = "";
        }
        else if (open)
        {
            i += c;
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    
    s.erase(0, 1);
    s.erase(s.length() - 1);
    
    vector<string>ss;
    slicingString(ss,s);

    sort(ss.begin(), ss.end(), compare);

    for (string& s : ss)
    {
        vector<string>im;
        char separator = ',';
        std::istringstream iss(s);
        std::string str_buf;
        while (getline(iss, str_buf, separator)) {
            int index = stoi(str_buf);
            if (!hash_table[index])
            {
                hash_table[index] = true;
                answer.push_back(index);
            }
        }
    }
    return answer;
}

int main()
{
    string a = "{{2,1,3},{2,1},{2},{2,1,3,4}}";
    solution(a);
    return 0;
}


```

## 다른 답안

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    int st[101010]={};
    vector<int> answer;
    string tmp;
    for(char i: s){
        if(i-'0' >=0 && i-'0' <=9){
            tmp += i;
        }
        else{
            if(tmp.length())
                st[stoi(tmp)]++, tmp.clear();
        }
    }
    vector<pair<int, int>> v;
    for(int i =0; i <101010; i++)
        if(st[i])
            v.push_back({st[i], i});
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(auto it: v) answer.push_back(it.second);
    return answer;
}
```

## 답안 해석
먼저 모든 숫자에 대해 st배열에 카운트한다.

존재하는 모든 숫자를 v에 (개수,해당 숫자)로 추가한다.
여기서 내림차순 정렬을 하는데 튜플을 집합기호로 표현할 때 보면 앞에있는 숫자일수록 더 많이 등장한다.  ex)(3,1,2) 튜플일 때, {3},{1,3},{2,1,3}, 3이 가장많이 등장했다. 이 특성을 이용해 구했다. 
