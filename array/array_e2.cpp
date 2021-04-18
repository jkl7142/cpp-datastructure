/*
*   Exercise 2 : 데이터 저장 컨테이너 만들기
*/

#include <array>
#include <iostream>
#include <type_traits>

// 컨테이너 생성
//template<typename ... Args>
// std::array 반환
//std::array<?, ?> build_array(Args&&... args)

// 원소 타입 & 개수 지정            // 후행 리턴 타입 지정
//auto build_array(Args&&... args) -> std::array<typename::common_type<Args...>::type, ?> {
    //using commonType = typename std::common_type<Args...>::type;
    // 배열 생성 코드 위치
//}

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)> {// sizeof...(args) : 원소 개수
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...}; // commonType으로 배열 생성
}

int main() {
    auto data = build_array(1, 0u, 'a', 3.2f, false);   // 다양한 타입의 데이터를 인자로 받음

    for (auto i : data) {
        std::cout << i << " ";  // 인자들이 모두 float 자료형으로 변환될 수 있어 최종 출력은 float 형식
    }
    std::cout << std::endl;

    // 문자열과 숫자를 모두 표현할 수 있는 공통 자료형이 없어 에러
    // auto data2 = build_array(1, "Packt", 2.0);

    return 0;
}