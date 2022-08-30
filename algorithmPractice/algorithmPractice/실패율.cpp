//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//bool compare(const pair<int, double>& a, const pair<int, double>& b)
//{
//    if (a.second == b.second)
//        return a.first < b.first;
//    return a.second > b.second;
//}
//
//vector<int> solution(int N, vector<int> stages) {
//    vector<int> answer;
//    vector<pair<int, double>> s;
//    int a = stages.size();
//    for (int i = 1; i <= N; i++)
//    {
//        int cnt = 0;
//        for (int j = 0; j < stages.size(); j++)
//        {
//            if (i == stages[j])cnt++;
//        }
//        // 왜 이 if코드를 넣으니까 통과지??
//		  // 아마도 double형이 0.000001 이런식으로 되어있어서 그런건가
//        if (cnt == 0)s.push_back(make_pair(i, 0));
//        else s.push_back(make_pair(i, (double)cnt / a));
//        a -= cnt;
//    }
//    sort(s.begin(), s.end(), compare);
//    for (int i = 0; i < s.size(); i++)
//    {
//        answer.push_back(s[i].first);
//    }
//    return answer;
//}
//int main()
//{
//    vector<int>a = { 2, 1, 2, 6, 2,7,7,7, 4, 3,4,1, 3 };
//    solution(6, a);
//    return 0;
//}
