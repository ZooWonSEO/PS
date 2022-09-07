## c++ 자료구조 및 STL

<hr>

### Pair
- 두가지 자료형을 하나의 쌍으로 표현할 수 있는 자료구조

```
pair<string, int> p;       // 선언
p = make_pair("abc", 1>);  // 값 삽입

```
<hr>

### vector
- 크기가 가변적인 배열인 자료구조

```
#include <vector>

vector<int> v;    // 선언
v.push_back(1);   // 마지막에 원소 삽입
v.pop_back();     // 마지막 원소 제거
v.size();         // 원소개수 반환
v.clear();        // 벡터 초기화
v.front();        // 첫번째 원소 반환
v.bakc();         // 마지막 원소 반환

sort(v.begin(), v.end());  // 벡터 오름차순 정렬

vector<pairt<int, int>> v;    // pair를 vector로 선언
v.push_back(make_pair(1,1));  // pair형 데이터 삽입
v[0].first;
v[0].second;

```

<hr>

### Stack
- LIFO(Last In First Out)인 자료구조

```
#include <stack>

stack<int>            s1;   // 선언1
stack<pair<int, int>> s2;   // 선언2

s1.push(1);   // top에 원소 삽입
s1.pop();     // top 원소 제거
s1.top();     // top 원소 반환
s1.size();    // stack 사이즈 반환
s1.empty();   // stack이 비어있는지 확인

s2.push(make_pair(1,1));
  
```

<hr>
  
### Queue
- FIFO(Fast In First Out)인 자료구조
- BFS를 구현할 때 유용하다.

```
#include <queue>

queue<int> q1;            // 선언1
queue<pair<int,int>> q2;  // 선언2

q1.push(1);   // back에 원소 삽입
q1.pop();     // back  제거
q1.front();   // 맨 앞 원소 반환
q1.back();    // 맨 뒤 원소 반환
q1.size();    // queue 사이즈 반환
q1.empty();   // queue가 비어있는지 확인

```

<hr>

### Deque
- Queue이지만 앞,뒤로 데이터를 삽입,삭제가 가능한 자료구조

```
#include <deque>

deque<int> d1;            // 선언1
deque<pair<int,int>> d2;  // 선언2

d1.push_front(1);   // deque 맨 앞에 원소 삽입
d1.push_back(1);    // deque 맨 뒤에 원소 삽입
d1.pop_front();     // deque 맨 앞 원소 삭제
d1.pop_back();      // deque 맨 뒤 원소 삭제
d1.size();          // deque 사이즈 반환
d1.empty();         // deque가 비어있는지 확인

```

<hr>

### Priority Queue
- heap으로 구현된 자료구조
- pair와 함께 사용되는 경우가 많으며, 비교는 첫번째요소가 같으면 두번째 요소로 비교한다.
- 기본형은 max-heap이다. min-heap으로 선인하기 위해서는 greater를 사용해야한다.

```
#include <queue>

priority_queue<int> pq;                                   // 선언1
priority_queue<pair<int,int>> pq2;                        // 선언2
priority_queue<int, vector<int>, less<int>> min_heap;     // 선언3
priority_queue<int, vector<int>, greater<int>> max_heap;  // 선언4


pq.push(1);   // pq top에 원소 삽입
pq.pop();     // pq top 원소 삭제
pq.top();     // pq top 원소 반환
pq.size();    // pq 사이즈 반환
pq.empty();   // pq가 비어있는지 확인
  
```

<hr>

### Unordered Map
- hash table 기반의 hash container이다.
- 중복된 데이터를 허용하지 않는다.

```
#include <unordered_map>


```


<hr>

### Map

```


```


<hr>

### Set


```


```


<hr>



### Bitset

<hr>
