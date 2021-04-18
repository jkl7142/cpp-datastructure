#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {

    // int형 벡터 선언
    std::vector<int> vec1;

    // 지정한 초깃값으로 이루어진 크기가 5인 벡터 선언
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    // 크기가 10인 벡터 선언
    std::vector<int> vec3(10);

    // 크기가 10이고, 모든 원소가 5로 초기화된 벡터 선언
    std::vector<int> vec4(10, 5);

    // 벡터에 새로운 원소 추가
    // vector.push_back(val) : 맨 마지막에 새로운 원소 추가
    // vector.insert(&, val) : 삽입할 위치에 원소 추가

    vec1.insert(vec1.begin(), 0);    // 맨 앞에 0 추가 : {0}
    vec1.push_back(1);               // 맨 뒤에 1 추가 : {0, 1}
    vec1.push_back(2);               // 맨 뒤에 2 추가 : {0, 1, 2}
    vec1.insert(vec1.begin(), 0);    // 맨 앞에 0 추가 : {0, 0, 1, 2}
    vec1.insert(find(vec1.begin(), vec1.end(), 1), 4);  // 1 앞에 4 추가 : {0, 0, 4, 1, 2}

    // vec.emplace_back() or emplace() 함수가 새 원소 위치에서 곧바로 객체가 생성되기 때문에 성능 향상에 도움이 됨

    // 백터 원소 제거
    // vector.pop_back() : 맨 마지막 원소 제거
    // vector.erase(&) : 해당 위치 원소 제거
    // vector.erase(&, &) : 시작부터 끝 바로 앞 원소까지 제거

    std::vector<int> vec5 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vec5.pop_back();            // 맨 마지막 원소 하나 제거 : {0, 1, 2, 3, 4, 5, 6, 7, 8}
    vec5.erase(vec5.begin());   // 맨 처음 원소 하나 제거 : {1, 2, 3, 4, 5, 6, 7, 8}
    vec5.erase(vec5.begin() + 1, vec5.begin() + 4); // 1번째 원소부터 4번째 앞 원소까지 제거 {1, 5, 6, 7, 8}

    // vector.clear() : 모든 원소를 제거하여 빈 벡터로 만듬
    // vector.reserve(capacity) : 백터에서 사용할 용량을 지정 (지정한 값이 현재 용량보다 크면 매개변수만큼 재할당, 같거나 작으면 아무런 동작을 하지 않음)
    // vector.shrink_to_fit() : 여분의 메모리 공간을 해제 (벡터 크기가 더 이상 변경되지 않을 때 사용하면 유용)

    /////////////////////////////////////////////////////////////
    // vector 할당자

    // vector.allocate()
    // vector.deallocate()
    // vector.construct()
    // vector.destroy()
}