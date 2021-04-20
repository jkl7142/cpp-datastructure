#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

int main() {
    
    // 덱을 스택처럼 사용할 경우
    std::deque<int> stk1;
    stk1.push_back(1);  // {1}
    stk1.push_back(2);  // {1, 2}
    stk1.pop_back();    // {1}
    stk1.push_front(0); // {0, 1} (스택에서는 지원하지 않는 동작)

    std::stack<int> stk2;
    stk2.push(1);   // {1}
    stk2.push(2);   // {1, 2}
    stk2.pop();     // {1}
    //stk2.push_front(0)  // 컴파일 에러

    // std::stack은 std::deque을 기본 컨테이너로 사용
    // stack.empty()
    // stack.size()
    // stack.top() : back() 동작
    // stack.push() : push_back() 동작
    // stack.pop() : pop_back() 동작
    // stack.emplace()

    // 기본 컨테이너를 지정하여 스택을 만들 경우
    std::stack<int, std::vector<int>> stk3; // 벡터를 이용하여 스택 생성
    std::stack<int, std::list<int>> stk4;   // 리스트를 이용하여 스택 생성

    return 0;
}