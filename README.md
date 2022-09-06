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
- #include <vector>

```
vector<int> v;    // 선언
v.push_back(1);   // 마지막에 데이터 추가
v.pop_back();     // 마지막 데이터 제거
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
- #include <stack>

```
stack<int>            s1;   // 선언1
stack<pair<int, int>> s2;   // 선언2

s1.push(1);   // top에 데이터 삽입
s1.pop();     // top 데이터 제거
s1.top();     // top 데이터 반환
s1.size();    // stack 크기 반환
s1.empty();   // stack이 비어있는지 확인

s2.push(make_pair(1,1));
  
```

<hr>
  
### Queue
- FIFO(Fast In First Out)인 자료구조
- #include <queue>
- BFS를 구현할 때 유용하다.

```
queue<int> q1;            // 선언1
queue<pair<int,int>> q2;  // 선언2

q1.push(1);
a1


```

### Priority Queue



### Set


### Map


### Unordered Map




### Bitset

<hr>
