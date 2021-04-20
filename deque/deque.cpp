#include <iostream>
#include <deque>

int main() {

    // ���Ϳ��� �ϱ����� push_front()�� pop_front()�� ����
    // ����� ť(double-ended queue)

    // deque.push_front()
    // deque.push_back()
    // deque.insert()
    // deque.emplace_front()
    // deque.emplace_back()
    // deque.emplace()
    // deque.pop_front()
    // deque.pop_back()
    // deque.erase()

    std::deque<int> deq = {1, 2, 3, 4, 5};
    deq.push_front(0);   // �� �տ� 0 �߰� : {0, 1, 2, 3, 4, 5}
    deq.push_back(6);    // �� �ڿ� 6 �߰� : {0, 1, 2, 3, 4, 5, 6}
    deq.insert(deq.begin() + 2, 10);    // �� �տ��� 2ĭ �ڿ� 10 �߰� : {0, 1, 10, 2, 3, 4, 5, 6}

    deq.pop_back();     // �� �� ���� ���� : {0, 1, 10, 2, 3, 4, 5}
    deq.pop_front();    // �� �� ���� ���� : {1, 10, 2, 3, 4, 5}
    deq.erase(deq.begin() + 1); // {1, 2, 3, 4, 5}
    deq.erase(deq.begin() + 3, deq.end());  // {1, 2, 3}

    return 0;
}