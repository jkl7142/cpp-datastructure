#include <iostream>
#include <queue>

int main() {

    // std::queue 역시 std::deque를 기본 컨테이너로 사용
    // queue.push() : push_back()
    // queue.pop() : pop_front()
    // queue.front() : 맨 앞 원소에 접근
    // queue.back() : 맨 끝 원소에 접근

    std::queue<int> q;
    q.push(1);  // {1}
    q.push(2);  // {1, 2}
    q.push(3);  // {1, 2, 3}
    q.pop();    // {2, 3}
    q.push(4);  // {2, 3, 4}

    return 0;
}