//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//// unordered_map���� ������ ���� �ذ��Ͽ���. 
//// ���� �ش� ������ Ű�� �������� �ʴ´ٸ� �߰��ϴ� �������� �� �� ������ ���ϸ��� �ִ��� �� �� �ִ�.
//// ���� �̾ƾ��ϴ� ���� ������ �� ���� ���ٸ� �̾ƾ��ϴ� ����� �ƹ��ų� 1������ ������ �װ� �ִ밳���̴�.
//// ���� �̾ƾ��ϴ� ���� ������ �� ���� ���ٸ� �ִ´�� 1������ �����Ŀ��� ������ �ߺ����� �ƹ��ų� �����Ѵ�.
//// ���� �� �� �� ���� ���� ��ȯ�ϸ� �ȴ�.
//
//int solution(vector<int> nums)
//{
//    int answer = 0;
//    unordered_map<int, int> map;
//
//    for (int i : nums)
//    {
//        if (map.end() == map.find(i))
//        {
//            map.insert(make_pair(i, 1));
//        }
//        else
//        {
//            map[i]++;
//        }
//    }
//
//    int k = map.size();
//    int n = nums.size() / 2;
//    if (k >= n)return n;
//    else
//    {
//        return k;
//    }
//
//    return answer;
//}
//int main()
//{
//    vector<int>a = { 2, 1, 3, 4, 1 };
//    solution(a);
//    return 0;
//}