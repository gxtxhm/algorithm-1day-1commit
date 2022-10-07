## 아이디어
보자마자 해쉬맵을 떠올렸다. 문자열과 인덱스를 key,value로 저장하면서
string으로 검색이 가능하기 때문이다.
2중 반복문으로 안쪽반복문에서 문자열길이를 1부터 늘리며 해쉬맵에 있는지 체크해서
최대한 긴 문자열을 구한다. 그리고 있던 문자열만큼 건너뛰고 똑같이 반복한다.

``` cpp

    #include <string>
    #include <vector>
    #include <unordered_map>


    using namespace std;

    vector<int> solution(string msg) {
        vector<int> answer;
        unordered_map<string, int>um;
        char al = 'A';

        for (int i = 0; i < 26; i++)
        {
            string s = "";
            s += al;
            um.insert(make_pair(s, i + 1));
            al++;
        }
        int r = 27;
        int index = 0;
        int len = 1;
        while (msg.length() >index)
        {
            len = 1;
            string s = msg.substr(index,len);
            int before = um[s];
            while (um.end() != um.find(s))
            {
                len++;
                before = um[s];
                s = msg.substr(index, len);
                if (msg.length() <= index + len+1)break;
            }
            index+=(len-1);
            um.insert(make_pair(s, r++));
            answer.push_back(before);
        }
        return answer;
    }

int main()
{
    solution("ABABABABABABABAB");
    return 0;
}

```