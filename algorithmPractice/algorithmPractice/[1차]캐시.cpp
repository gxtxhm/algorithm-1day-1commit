//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool isCacheHit(string& s, int cacheSize, vector<string>& cache)
//{
//    if (cacheSize==0) return false;
//    
//        // 캐시 미스일 경우
//        if (cache.end() == find(cache.begin(), cache.end(), s))
//        {
//            //맨 앞에 삽입
//            cache.insert(cache.begin(), s);
//            if (cache.size()-1 == cacheSize)
//            {
//                // 캐시가 꽉찼다면 맨 뒤에 하나 뺴기
//                cache.pop_back();
//            }
//            return false;
//        }
//        // 캐시 히트일 경우
//        else
//        {
//            // 데이터 맨 앞으로 보내기
//            cache.erase(find(cache.begin(), cache.end(), s));
//            cache.insert(cache.begin(), s);
//            return true;
//        }
//    
//    
//   
//}
//
//int solution(int cacheSize, vector<string> cities) {
//    int answer = 0;
//    vector<string>cache;
//    int index;
//    
//    // 전부 소문자로
//    for (int i = 0; i < cities.size(); i++)
//    {
//        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
//    }
//    
//    for (string s : cities)
//    {
//        //캐시 Hit이면
//        if (isCacheHit(s, cacheSize, cache))
//        {
//            answer++;
//        }
//        //캐시 miss면
//        else
//        {
//            answer += 5;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string>c = { "Jeju", "Pangyo", "NewYork", "newyork" };
//    solution(2, c);
//    return 0;
//}