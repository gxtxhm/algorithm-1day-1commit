//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//// w,h�� ��� ������ ���������ϰ��ϴ� �ּ����� ũ���.
//// ���� ����ŭ �ݺ����ϸ� ���� �ݺ����� ������ ũ�⸦ w,h�� ���簡���Ѱ��� ������
//// ���� �Ұ��ϴٸ� w,h�� ������Ʈ�Ѵ�. 
//// �� ��, ȸ���� w�� �׻� ū ���� �ϵ��� �Ͽ� �ذ��Ѵ�.
//
//int solution(vector<vector<int>> sizes) {
//    int answer = 0;
//
//    // ù��° �������� �ʱ� ũ�� ����
//    // w�� ū ��
//    int w = (sizes[0][0] < sizes[0][1]) ? sizes[0][1] : sizes[0][0];
//    int h = (sizes[0][0] < sizes[0][1]) ? sizes[0][0] : sizes[0][1];
//    for (vector<int> size : sizes)
//    {
//        //���� ������ ���Լ����� �����Ѱ�?
//
//        //���� ���� ũ���� ���� ���� �� �� ū �Ͱ� ���� �� ����
//        int bigger = (size[0] < size[1]) ? size[1] : size[0];
//        int smaller= (size[0] < size[1]) ? size[0] : size[1];
//        
//        // ���� �Ұ���
//        if (bigger > w||smaller>h)
//        {
//            // ���� ������ ���� ������ ũ��� ��ü
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