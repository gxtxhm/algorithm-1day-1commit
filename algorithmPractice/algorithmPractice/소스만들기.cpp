//#include <vector>
//#include <iostream>
//using namespace std;
//
//// ��� �� �����佺�׳׽��� ü�� �̿��� �Ҽ�ã�� �˰����� �н��Ͽ� �ٷ� �����غ��Ҵ�.
//// 3�� ������ ���� �ִ� 3õ�� ���� �� �����Ƿ� 3õ������ �� �� �Ҽ��� ���� ���� ã�Ƴ���.
//// �װ��� �����佺�׳׽��� ü�� �̿��Ͽ� ���ߴ�. 
//// �׸��� 3�� ������ ���� ��� ����� ���� ���ϰ� �� ����� ���� �Ҽ����´��� �̸� ���س��� �迭�� ����
//// Ȯ���Ѵ�.
//int solution(vector<int> nums) {
//    int answer = 0;
//
//    int v[3000] = { 0, };
//
//
//    // 3õ������ �Ҽ��� ���� �ɷ�����
//    for (int i = 2; i <= 3000; i++)
//    {
//        if (v[i] == 0)
//        {
//            for (int j = i + i; j <= 3000; j += i)
//                v[j] = 1;
//        }
//    }
//
//
//    int size = nums.size();
//    for (int i = 0; i < size - 2; i++)
//    {
//        for (int j = i + 1; j < size - 1; j++)
//        {
//            for (int k = j + 1; k < size; k++)
//            {
//                if (v[nums[j] + nums[k] + nums[i]] == 0)answer++;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<int>a = { 1, 2, 3, 4 };
//    solution(a);
//    return 0;
//}