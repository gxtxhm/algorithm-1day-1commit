//#include <string>
//#include <vector>
//#include<iostream>
//using namespace std;
//
//// �� �ȵǳ� �ô��� cnt�� 0�ΰ�� cnt-1 �ε����� �����ϰ� �ȴ�. ������ �����ϴµ� 
//// �׽�Ʈ ��� ���ж�� ����. �̷� ��쵵 �����ؾ߰ڴ�.
//
//int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//vector<string> bb = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
//string solution(int a, int b) {
//    string answer = "";
//    int cnt = 0;
//    for (int i = 0; i < a - 1; i++)cnt += month[i];
//
//    cnt += (b + 5);
//
//    cnt %= 7;
//    if (cnt == 0)cnt = 7;
//    answer += bb[cnt - 1];
//    return answer;
//}
//
//int main()
//{
//    cout << solution(1, 6);
//    return 0;
//}