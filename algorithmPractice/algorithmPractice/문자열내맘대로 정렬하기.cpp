//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//int num;
//
//bool compare(string a, string b)
//{
//    //���� �ڵ�� ���� �ڵ��� ���̰� ����?
//    // �ؿ� �ڵ���� ����, �� �ڵ�� �����̴�.
//    // �� ������ else ���� return false�� �ƴ� false�� ��� ������ ���Ծ���. 
//    // �㹫������ �ڵ带 �� �� �м��ؾ߰ڴ�. 
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