//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int n, long long left, long long right) {
//    vector<int> answer;
//    long long row = 0, col = 0;
//    for (long long cnt = left; cnt <= right; cnt++)
//    {
//        row = cnt / (n);
//        col = cnt % (n);
//
//        answer.push_back(max(row,col)+1);
//    }
//
//    return answer;
//}