//#include <string>
//#include <vector>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//
////contirbution에 적용이 안돼서 깃 등록 이메일을 변경하였다.
//
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer;
//
//    //command가 2,5,3 이라면 array의 [1]~[4]까지를 data에 저장한 후, 오름차순정렬을 한다.
//    // data[command[2]-1]번째 수를 answer에 저장한다.
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