#include <iostream>
#include <queue>

int main() {

    // std::queue ���� std::deque�� �⺻ �����̳ʷ� ���
    // queue.push() : push_back()
    // queue.pop() : pop_front()
    // queue.front() : �� �� ���ҿ� ����
    // queue.back() : �� �� ���ҿ� ����

    std::queue<int> q;
    q.push(1);  // {1}
    q.push(2);  // {1, 2}
    q.push(3);  // {1, 2, 3}
    q.pop();    // {2, 3}
    q.push(4);  // {2, 3, 4}

    return 0;
}