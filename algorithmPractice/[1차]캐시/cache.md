## 아이디어


들어오는 데이터마다 캐시를 확인하여 캐시Hit이면 실행시간 +1, 캐시miss면 실행시간 +5를 한다. 

캐시는 리스트로 처리하는데 캐시Hit일때는 맨 앞 해당데이터를 리스트에서 삭제하고 맨 앞에 다시 추가한다.
캐시miss일때는 먼저 맨 앞에 데이터를 추가하고 캐시 크기가 정해진 크기를 넘어가면 맨 뒤 원소를 삭제한다.

## 필요한 지식

LRU(Least Recently Used) : 페이지 교체 알고리즘 중 하나로 가장 오랫동안 참조되지 않은 페이지를 교체하는 방식이다.
캐시에 있는 데이터 중 가장최근에 사용된 데이터를 맨 앞으로 놓고 오래된 데이터가 뒤로 밀리는 방식이다.

## 새로 사용해본 c++기능

```cpp 
vector<string>cache;
cache.insert(cache.begin(), s);
```
insert( iterator position, const T& x)함수는  position위치에 x값을 대입하고 
기존 position위치부터 뒤에 있는 원소를 한 칸씩 뒤로 민다.

```cpp
cache.erase(find(cache.begin(), cache.end(), s));
```

erase(const_iterator position)함수는 position위치의 원소를 삭제하고 그 뒤의 데이터를 한 칸씩 당긴다.