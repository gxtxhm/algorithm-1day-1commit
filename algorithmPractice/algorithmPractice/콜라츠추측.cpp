//#include <string>
//#include <vector>
//
//// �ݶ��� ���� �����ε�, �׽�Ʈ���̽� 1���� ������ ���캸�Ҵ�.
//// �� ������ ��� int�� ������ �Ѿ�� ������ longlong������ ����Ÿ���� �ٲ������ؼ� ����ؾ��Ѵ�.
//// ������ Ǯ ��, �������� ����������� �����Ͽ� ����Ÿ���� �����ϴ� �͵� �Ű��� ��߰ڴ�.
//
//
//using namespace std;
//
//int solution(int num) {
//    int answer = 0;
//    int cnt = 0;
//    if (num == 1)return 0;
//    
//
//    while (num > 1)
//    {
//        if (cnt == 500)return -1;
//        if (num % 2 == 0)num /= 2;
//        else if (num % 2 == 1)num = (num * 3 + 1);
//        cnt++;
//    }
//
//    return cnt;
//}
//
//int main()
//{
//    solution(626331);
//    return 0;
//}