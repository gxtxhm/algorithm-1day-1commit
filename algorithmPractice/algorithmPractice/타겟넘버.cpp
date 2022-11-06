//#include <string>
//#include <vector>
//
//using namespace std;
//
//int cnt = 0;
//
//void recur(int index,vector<int>&numbers,int target,int curNum)
//{
//    if (index==numbers.size())
//    {
//        if(target == curNum)cnt++;
//        return;
//    }
//    recur(index + 1, numbers, target, curNum + numbers[index]);
//    recur(index + 1, numbers, target, curNum - numbers[index]);
//}
//
//int solution(vector<int> numbers, int target) {
//    recur(0,numbers, target, 0);
//    return cnt;
//}
//int main()
//{
//    vector<int> a = { 1,1,1,1,1 };
//    solution(a, 3);
//    return 0;
//}