#include <iostream>
#include <queue>
#include <vector>

int main() {

    // �켱���� ť = ��
    // std::priority_queue�� std::vector�� �⺻ �����̳ʷ� ���

    std::priority_queue<int> pq;    // �⺻ ��������
    std::priority_queue<int, std::vector<int>, std::less<int>> pq1; // ���� �����ϰ� ��������
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;    // ��������

    // pq.empty()
    // pq.size()
    // pq.top()
    // pq.push(val)
    // pq.pop()

    return 0;
}