/*
*   Exercise 3 : 연결 리스트에서 remove_if() 함수를 이용한 조건부 원소 삭제
*   선거권 검사 프로그램
*/

#include <string>
#include <iostream>
#include <forward_list>

struct citizen {
    std::string name;
    int age;
};

std::ostream &operator<<(std::ostream &os, const citizen &c) {
    return (os << "[" << c.name << ", " << c.age << "]");
}

int main() {

    std::forward_list<citizen> citizens = {
        {"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
    };

    auto citizens_copy = citizens;  // 깊은 복사

    std::cout << "전체 시민들: ";
    for (const auto &c : citizens)
        std::cout << c << " ";
    std::cout << std::endl;

    // 나이 정보를 이용하여 투표권이 없는 시민을 리스트에서 제거
    citizens.remove_if([](const citizen &c) {   // 람다 표현식
        // 나이가 19세이하면 리스트에서 제거
        return (c.age < 19);        // 결과가 참이면 원소를 제거
    });

    std::cout << "투표권이 있는 시민들: ";
    for (const auto &c : citizens)
        std::cout << c << " ";
    std::cout << std::endl;

    // 내년에 새로 투표권이 생기는 사람
    citizens_copy.remove_if([](const citizen &c) {
        return (c.age != 18);
    });

    std::cout << "내년에 투표권이 생기는 시민들: ";
    for (const auto &c : citizens_copy)
        std::cout << c << " ";
    std::cout << std::endl;

    return 0;
}