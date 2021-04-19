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

    // 연결 리스트 정렬
    // forward_list.sort() : 오름차순 정렬
    // forward_list.sort(비교 함수) : 비교 함수 조건에 맞게 정렬
    
    std::forward_list<int> list1 = {23, 0, 1, -3, 34, 32};

    list1.sort();   // {-3, 0, 1, 23, 32, 34}
    list1.sort(std::greater<int>());    // {34, 32, 23, 1, 0, -3} 내림차순 정렬

    // forward_list.reverse() : 역순으로 변경
    // forward_list.unique() : 중복되는 원소에 대해 첫 번째만 남기고 나머지는 제거
    // * unique()는 인접한 원소끼리 비교를 하기 때문에 정렬한 후 함수를 사용해야 함

    std::forward_list<int> list2 = {2, 53, 1, 0, 4, 10};
    list2.reverse();    // {10, 4, 0, 1, 53, 2}

    list2 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    list2.unique(); // {0, 1, 0, 1, -1, 10, 5, 10, 0}

    list2 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    list2.sort();   // {-1, 0, 0, 0, 1, 1, 5, 5, 10, 10}
    list2.unique(); // {-1, 0, 1, 5, 10}

    // 특정 원소가 바로 앞 원소보다 2 이상 크지 않으면 삭제
    list2.unique([](int a, int b) { return (b - a) < 2; }); // {-1, 1, 5, 10}

    return 0;
}