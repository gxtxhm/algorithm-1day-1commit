//#include <string>
//#include <vector>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//
////contirbution�� ������ �ȵż� �� ��� �̸����� �����Ͽ���.
//
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer;
//
//    //command�� 2,5,3 �̶�� array�� [1]~[4]������ data�� ������ ��, �������������� �Ѵ�.
//    // data[command[2]-1]��° ���� answer�� �����Ѵ�.
//    for (vector<int> command : commands)
//    {
//        vector<int>data;
//        for (int i = command[0]-1; i <= command[1]-1; i++)
//        {
//            data.push_back(array[i]);
//        }
//        sort(data.begin(), data.end());
//  /*      for (int i : data)
//        {
//            printf("%d ", i);
//        }
//        printf("\n");*/
//        answer.push_back(data[command[2]-1]);
//
//    }
//    return answer;
//}
//int main()
//{
//    vector<int>a = { 1, 5, 2, 6, 3, 7, 4 };
//
//    vector<vector<int>>b = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
//    solution(a, b);
//    return 0;
//}