//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//// w,h는 모든 명함을 수납가능하게하는 최소한의 크기다.
//// 명함 수만큼 반복을하며 현재 반복중인 명함의 크기를 w,h가 감당가능한가를 따지고
//// 감당 불가하다면 w,h를 업데이트한다. 
//// 이 때, 회전은 w에 항상 큰 값이 하도록 하여 해결한다.
//
//int solution(vector<vector<int>> sizes) {
//    int answer = 0;
//
//    // 첫번째 명함으로 초기 크기 설정
//    // w에 큰 거
//    int w = (sizes[0][0] < sizes[0][1]) ? sizes[0][1] : sizes[0][0];
//    int h = (sizes[0][0] < sizes[0][1]) ? sizes[0][0] : sizes[0][1];
//    for (vector<int> size : sizes)
//    {
//        //현재 지갑이 명함수납이 가능한가?
//
//        //현재 명함 크기의 가로 세로 중 더 큰 것과 작은 것 구분
//        int bigger = (size[0] < size[1]) ? size[1] : size[0];
//        int smaller= (size[0] < size[1]) ? size[0] : size[1];
//        
//        // 수납 불가능
//        if (bigger > w||smaller>h)
//        {
//            // 현재 명함을 수납 가능한 크기로 교체
//            if (bigger > w)
//            {
//                w = bigger;
//            }
//            if (smaller > h)
//            {
//                h = smaller;
//            }
//        }
//    }
//
//    return (answer = w * h);
//}
//
//int main()
//{
//    vector<vector<int>> a = { {60, 50},{30, 70},{60, 30},{80, 40} };
//    cout << solution(a);
//    return 0;
//}