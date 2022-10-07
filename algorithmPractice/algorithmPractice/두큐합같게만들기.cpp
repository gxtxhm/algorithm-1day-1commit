//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int sumVector(vector<int>q)
//{
//    int r = 0;
//    for (int i : q)r += i;
//    return r;
//}
//
//int solution(vector<int> queue1, vector<int> queue2) {
//    int answer = -2;
//
//    long s1 = sumVector(queue1);
//    long s2 = sumVector(queue2);
//    if ((s1 + s2) % 2 != 0)return -1;
//    
//    queue<int>q1, q2;
//    for (int i : queue1)q1.push(i);
//    for (int i : queue2)q2.push(i);
//    int p1 = 0, p2 = 0;
//    int len = q1.size()*2;
//    while (p1<len&&p2<len)
//    {
//        if (s1 == s2)return p1+p2;
//        else if (s1 > s2)
//        {
//            int value = q1.front();
//            q1.pop();
//            s1 -= value;
//            s2 += value;
//            q2.push(value);
//            p1++; 
//        }
//        else
//        {
//            int value = q2.front();
//            q2.pop();
//            s1 += value;
//            s2 -= value;
//             p2++;
//            q1.push(value);
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    
//    return 0;
//}