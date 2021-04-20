#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

int main() {
    
    // ���� ����ó�� ����� ���
    std::deque<int> stk1;
    stk1.push_back(1);  // {1}
    stk1.push_back(2);  // {1, 2}
    stk1.pop_back();    // {1}
    stk1.push_front(0); // {0, 1} (���ÿ����� �������� �ʴ� ����)

    std::stack<int> stk2;
    stk2.push(1);   // {1}
    stk2.push(2);   // {1, 2}
    stk2.pop();     // {1}
    //stk2.push_front(0)  // ������ ����

    // std::stack�� std::deque�� �⺻ �����̳ʷ� ���
    // stack.empty()
    // stack.size()
    // stack.top() : back() ����
    // stack.push() : push_back() ����
    // stack.pop() : pop_back() ����
    // stack.emplace()

    // �⺻ �����̳ʸ� �����Ͽ� ������ ���� ���
    std::stack<int, std::vector<int>> stk3; // ���͸� �̿��Ͽ� ���� ����
    std::stack<int, std::list<int>> stk4;   // ����Ʈ�� �̿��Ͽ� ���� ����

    return 0;
}