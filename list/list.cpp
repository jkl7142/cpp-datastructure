#include <iostream>
#include <list>
#include <vector>

// 이중 연결 리스트 구조
struct doubly_linked_list_node {
    int data;
    doubly_linked_list_node* next;
    doubly_linked_list_node* prev;
};

int main() {

    // forward_list와 차이점
    // 1. 역방향 이동 가능
    // 2. 마지막 원소를 지정한 빠른 push_back(), emplace_back(), pop_back() 지원
    // 3. 리스트 크기를 반환하는 size() 지원

    // 양방향 반복자 O(n) : 순방향 & 역방향 이동 가능

    // 반복자 무효화 : 연결 리스트에서는 삽입/삭제 시 반복자가 무효화되지 않음

    // 벡터의 경우
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto v_it4 = vec.begin() + 4;   // vec[4] = 5
    vec.insert(vec.begin() + 2, 0); // v_it4 반복자는 무효화됨
    // (새로 메모리 공간을 할당하고 기존의 모든 원소를 복사하기 때문에 기존에 사용하던 모든 반복자, 포인터, 참조가 무효화)

    // 리스트의 경우
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto l_it4 = next(lst.begin(), 4);
    lst.insert(next(lst.begin(), 2), 0);    // l_it4 반복자는 여전히 유효

    return 0;
}