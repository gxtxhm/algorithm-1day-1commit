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