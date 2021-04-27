/*
*   Exercise 13 : 정수 값을 저장하는 사전
*/

#include <iostream>
#include <vector>

using uint = unsigned int;

class hash_map {
    std::vector<int> data;

public:
    hash_map(size_t n) {
        data = std::vector<int>(n, -1);
    }

    void insert(uint value) {
        int n = data.size();
        data[value % n] = value;    // 해시 값 : value % n  // 값이 중복될 경우 나중에 삽입한 값만 저장됨
        std::cout << value << "을(를) 삽입했습니다." << std::endl;
    }

    // lookup
    bool find(uint value) {
        int n = data.size();
        return (data[value % n] == value);
    }

    void erase(uint value) {
        int n = data.size();
        if (data[value % n] == value) {
            data[value % n] = -1;
            std::cout << value << "을(를) 삭제했습니다." << std::endl;
        }
    }
};

int main() {

    hash_map map(7);

    auto print = [&](int value) {
        if (map.find(value))
            std::cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
        else
            std::cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
        std::cout << std::endl;
    };

    map.insert(2);  // [2]
    map.insert(25); // [4]
    map.insert(10); // [3]
    print(25);

    map.insert(100); // [2]
    print(100);
    print(2);       // collision

    map.erase(25);

    return 0;
}