#include <iostream>
#include <queue>
#include <vector>

int main() {

    // 우선순위 큐 = 힙
    // std::priority_queue는 std::vector를 기본 컨테이너로 사용

    std::priority_queue<int> pq;    // 기본 내림차순
    std::priority_queue<int, std::vector<int>, std::less<int>> pq1; // 위와 동일하게 내림차순
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;    // 오름차순

    // pq.empty()
    // pq.size()
    // pq.top()
    // pq.push(val)
    // pq.pop()

    return 0;
}