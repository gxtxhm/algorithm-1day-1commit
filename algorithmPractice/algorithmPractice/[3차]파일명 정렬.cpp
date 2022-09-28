//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> split(string s)
//{
//    vector<string>n;
//    string a = "";
//    int i = 0;
//    for (i=0;i<s.length();i++)
//    {
//        if (isdigit(s[i]))
//        {
//            n.push_back(a);
//            a = ""; break;
//        }
//        else
//        {
//            a += s[i];
//        }
//    }
//    
//    for (i; i < s.length(); i++)
//    {
//        if (!isdigit(s[i]))
//        {
//            n.push_back(a);
//            a = ""; break;
//        }
//        else
//        {
//            a += s[i];
//        }
//    }
//    if (i == s.length())
//    {
//        n.push_back(a); n.push_back("");
//    }
//    else n.push_back(s.substr(i));
//    return n;
//}
//
//bool comp(const vector<string>& a,const vector<string>& b)
//{
//    string ah = "";
//    string bh = "";
//
//    for (char c : a[0])
//    {
//        ah += tolower(c);
//    }
//    for (char c : b[0])
//    {
//        bh += tolower(c);
//    }
//    if (ah < bh)return true;
//    else if (ah > bh)return false;
//    else
//    {
//        int an = stoi(a[1]);
//        int bn = stoi(b[1]);
//
//        if (an < bn)return true;
//        else return false;
//    }
//    return false;
//}
//
//vector<string> solution(vector<string> files) {
//    vector<string> answer;
//    
//    vector<vector<string>>f;
//
//    for (string s : files)
//    {
//        f.push_back(split(s));
//    }
//    //Á¤·Ä
//    stable_sort(f.begin(), f.end(), comp);
//
//    for (auto s : f)
//    {
//        string r = "";
//        r = s[0] + s[1] + s[2];
//        answer.push_back(r);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> a = { "foo9.txt","foo010bar020.zip","F-15"};
//    solution(a);
//    return 0;
//}