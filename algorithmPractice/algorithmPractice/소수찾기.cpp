//#include <string>
//#include <vector>
//
//using namespace std;
//
//// ù��° Ǯ��
//int solution(int n) {
//    int answer = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        int cnt = 0;
//        for (int j = 2; j * j <= i; j++)
//        {
//            if (i % j == 0)cnt++;
//        }
//        if (cnt == 0)answer++;
//    }
//    return answer;
//}
//// 
//// 
//// �ι�° Ǯ�� - ȿ���� ��� Ǯ��
//// �����佺�׳׽��� ü��� ���� �̷��� �����ؾ� Ǯ �� �ִ�. 
//// �� �̷��� 2���� �����ؼ� �� ���� ����� �� �����س����� ������� �Ҽ��� ã�� �̷��̴�.
//// 2�� 3�� �Ҽ��̱� ������ 2���� �����ؼ� n���� for���� ���� �ϴ� 2,3,4...�ǹ������ ���ʷ� ���ŵǸ�
//// ���Ű� �������� ���� �Ҽ��̴�.
//int solution(int n) {
//    int answer = 0;
//    int v[1000001] = { 0, };
//    for (int i = 2; i <= n; i++)
//    {
//        if (v[i] == 0)
//        {
//            answer++;
//            for (int j = i; j <= n; j += i)
//            {
//                v[j] = 1;
//            }
//        }
//    }
//    return answer;
//}