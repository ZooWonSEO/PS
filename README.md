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
vector<int> v;    // 선언
v.push_bakc(1);   // 마지막에 데이터 추가
v.pop_back();     // 마지막 데이터 제거
v.size();         // 원소개수 반환
v.clear();        // 벡터 초기화
v.front();        // 첫번째 원소 반환
v.bakc();         // 마지막 원소 반환

sort(v.begin(), v.end());  // 벡터 오름차순 정렬

vector<pairt<int, int>> v; // pair를 vector로 선언
v[0].first;
v[0[.second;

```

<hr>

### Stack



### Queue


### Priority Queue


### Set


### Map


### Unordered Map




### Bitset

<hr>
