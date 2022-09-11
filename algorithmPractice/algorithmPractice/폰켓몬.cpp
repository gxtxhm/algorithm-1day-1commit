//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//// unordered_map으로 문제를 쉽게 해결하였다. 
//// 만약 해당 종류의 키가 존재하지 않는다면 추가하는 형식으로 총 몇 종류의 포켓몬이 있는지 알 수 있다.
//// 만약 뽑아야하는 수가 종류의 수 보다 적다면 뽑아야하는 수대로 아무거나 1마리씩 집으면 그게 최대개수이다.
//// 또한 뽑아야하는 수가 종류의 수 보다 많다면 있는대로 1마리씩 뽑은후에는 무조건 중복으로 아무거나 골라야한다.
//// 따라서 둘 중 더 작은 수를 반환하면 된다.
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