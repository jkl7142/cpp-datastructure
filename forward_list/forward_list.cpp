#include <iostream>
#include <forward_list>

int main(int argc, char* argv[]) {

    // 연결리스트 생성
    std::forward_list<int> fwd_list1 = {1, 2, 3};

    // 연결리스트 원소 추가
    // forward_list.push_front(val) : 맨 앞에 원소 추가
    // forward_list.insert_after(&, val) : & 위치 다음에 원소 추가

    fwd_list1.push_front(0); // 맨 앞에 0 추가 : {0, 1, 2, 3}

    auto it = fwd_list1.begin();
    fwd_list1.insert_after(it, 5);   // 첫 번째 원소 뒤에 5 추가 : {0, 5, 1, 2, 3}
    fwd_list1.insert_after(it, 6);   // 첫 번째 원소 뒤에 6 추가 : {0, 6, 5, 1, 2, 3}

    // forward_list.emplace_front() or .emplace_after() // 추가적인 복사 또는 이동 x -> 효율적

    // 연결리스트 원소 삭제
    // forward_list.pop_front() : 맨 앞에 원소 삭제
    // forward_list.erase_after(&) : & 위치 다음 원소 삭제
    // forward_list.erase_after(&, &) : & 위치 다음부터 & 바로 전 원소까지 삭제

    std::forward_list<int> fwd_list2 = {1, 2, 3, 4, 5};

    fwd_list2.pop_front();  // 맨 앞에 원소를 삭제 : {2, 3, 4, 5}
    
    auto it = fwd_list2.begin();
    fwd_list2.erase_after(it);  // 첫 번째 원소 다음 원소를 삭제 : {2, 4, 5}
    
    fwd_list2.erase_after(it, fwd_list2.end()); // 맨 앞의 원소 다음부터 마지막 원소까지 삭제 : {2}

    // forward_list.remove(val) : val와 값이 같은 원소를 모두 삭제
    // forward_list.remove_if() : 조건자 함수를 받아 true를 반환하는 원소를 모두 삭제

    return 0;
}