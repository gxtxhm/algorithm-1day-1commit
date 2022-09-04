//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//int num;
//
//bool compare(string a, string b)
//{
//    //위의 코드와 밑의 코드의 차이가 뭐지?
//    // 밑에 코드들은 정답, 이 코드는 오답이다.
//    // 아 마지막 else 문에 return false가 아닌 false만 적어서 오답이 나왔었다. 
//    // 허무하지만 코드를 더 잘 분석해야겠다. 
//    if (a[num] < b[num])return true;
//    else if (a[num] == b[num])return a < b;
//    else  false;
//
//    /*if (s1[idx] < s2[idx])
//        return true;
//    else if (s1[idx] == s2[idx])
//        return s1 < s2;
//    else return false;*/
//    
//    /*if (a[num] == b[num]) {
//        return a < b;
//    }
//    else {
//        return a[num] < b[num];
//    }*/
//
//}
//
//vector<string> solution(vector<string> strings, int n) {
//    vector<string> answer;
//    num = n;
//    sort(strings.begin(), strings.end(), compare);
//    answer = strings;
//    return answer;
//}
//int main()
//{
//    vector<string>a = { "zbcde", "ybcdf", "xbcdg","ybccf"};
//      
//    solution(a, 1);
//    return 0;
//}