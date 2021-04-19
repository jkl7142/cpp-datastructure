/*
*   Exercise 4 : 다양한 반복자로 이동하기
*/

#include <iostream>
#include <forward_list>
#include <vector>

int main() {

    // std::vector
    std::vector<std::string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
        "Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
        "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
    };

    // 시간 복잡도 O(1)
    auto it = vec.begin();
    std::cout << "가장 최근 우승자: " << *it << std::endl;

    it += 8;
    std::cout << "8년 전 우승자: " << *it << std::endl;

    advance(it, -3);
    std::cout << "그후 3년 뒤 우승자: " << *it << std::endl;

    // std::forward_list
    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    // 시간 복잡도 O(n)
    auto it1 = fwd.begin();
    std::cout << "가장 최근 우승자: " << *it1 << std::endl;

    advance(it1, 5);
    std::cout << "5년 전 우승자: " << *it1 << std::endl;

    // advance(it1, -2) // 연결 리스트는 역방향 이동 x

    // it1 += 2;    // 연결 리스트 += 연산자 x


    return 0;
}